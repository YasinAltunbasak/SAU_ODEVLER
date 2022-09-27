#Yasin Altunbaşak G1912100386

import os  
import numpy as np 
import pandas as pd 
import seaborn as sn
import keras
import matplotlib.pyplot as plt
from keras.datasets import cifar100
from keras.preprocessing import image
from keras import models, layers, optimizers

from tensorflow.keras.layers import Conv2D, Flatten, Dense, MaxPool2D #tensorflowdaki bu kütüphaneleri neden açamadığımı bulamadım.
from tensorflow.keras.models import Sequential
from tensorflow.keras.utils import to_categorical
from keras.preprocessing.image import ImageDataGenerator
from sklearn.metrics import confusion_matrix

# Load cifar 100 dataset. Separate train and test data set from cifar 100 dataset.
(train_images,train_labels),(test_images,test_labels) = cifar100.load_data() 

print(train_images.shape, train_labels.shape)
print(test_images.shape, test_labels.shape)

my_class = {17: "castle",22: "clock",4: "lamp",51: "mushroom",59: "pine_tree",81: "streetcar",94: "wardrobe"}



def save_resimler(x,y,my_class,dosya_yol):
    for i,j in my_class.items():
        sinif_yol = os.path.join(dosya_yol, j)
        os.mkdir(sinif_yol)
        resimler = x[y[:,0] == i]
        for k,resim in enumerate(resimler):
            plt.imsave(sinif_yol +"/"+ str(k)+".png",resim)   
veriseti_path = "cifar100_siniflar"

os.mkdir(veriseti_path)

train_dir = os.path.join(veriseti_path, 'train')
os.mkdir(train_dir)
test_dir = os.path.join(veriseti_path, 'test')
os.mkdir(test_dir)

save_resimler(train_images,train_labels,my_class,train_dir)
save_resimler(test_images,test_labels,my_class,test_dir)

epochs = 20                    # 30 epoch ile eğitim yapılacaktır.
batch_size = 40                # Her iterasyonda 50 fotoğraf alınır.

num_classes = len(my_class) # veri setinde 7 sınıf bulunmakta bu sınıfları len fonksiyon ile alıyoruz.

width = train_images.shape[1]
height = train_images.shape[2]

# Daha fazla veri örneği için Data Augmentation Metodu.
def make_generator():
    train_datagen = image.ImageDataGenerator(rescale=1./255,
                                         featurewise_center=False,             # Giriş verilerinin ortalamasının 0'lanması
                                         samplewise_center=False,              # Herbir örnek verinin ortalamasının 0'a eşitlenmesi
                                         featurewise_std_normalization=False,  # Giriş verilerinin, veri setinin standart varyans değerine bölünmesi
                                         samplewise_std_normalization=False,   # Herbir verinin standart varyans değerine bölünmesi
                                         zca_whitening=False,                  # "ZCA whitening" metodunun uygulanması
                                         rotation_range=0,                     # Resimlerin bir sınır aralığında gelişi güzel döndürülmesi (degrees, 0 to 180)
                                         width_shift_range=0.1,                # Görüntüleri rasgele olarak yatay olarak kaydırılır
                                         height_shift_range=0.1,               # Görüntüleri rasgele olarak dikey olarak kaydırılır
                                         shear_range=0.15,                     # Görüntüleri üzerinde rasgele makaslama
                                         zoom_range=0.15,                      # Görüntüleri üzerinde rasgele yakınlaştırılıyor
                                         horizontal_flip=True,                 # Fotoğrafı yatay düzlemde rastgele çevirme.
                                         vertical_flip=False)                  # Resimlerin gelişigüzel bir şekilde dikey olarak çevirilmesi
        

    test_datagen = image.ImageDataGenerator(rescale=1./255)

    train_datagen = train_datagen.flow_from_directory(directory = train_dir, 
                                                   target_size = (width,height), 
                                                   class_mode = "categorical", 
                                                   batch_size = 50, # Her batch 50 eğitim görüntüsü içerir.
                                                       shuffle=True,
                                                       seed=42) 

    test_datagen = test_datagen.flow_from_directory(directory = test_dir, 
                                                 target_size = (width,height),
                                                 class_mode = "categorical",
                                                 batch_size = 50,
                                                 shuffle=False, 
                                                 seed=42)
    return train_datagen, test_datagen

train_gen,test_gen = make_generator()

def get_image_via_class():
    labels = list(my_class.keys())

    fig,ax = plt.subplots(len(labels),10,figsize=(15,10))

    for i in range(len(labels)):
        images = train_images[train_labels[:,0] == labels[i]]
        ax[i,0].axis("off")
        ax[i,0].text(-0.5,0.5,my_class[labels[i]],fontdict={"size":15})
    
        for j in range(1,10):
            ax[i,j].axis("off")
            ax[i,j].imshow(images[j])
        
    plt.show()
    

get_image_via_class()

def create_model(loss_function):
    model = models.Sequential()
    num_cell = 3
    model.add(layers.Conv2D(32,(3,3),padding="same",activation="relu", strides=(1,1),
                            input_shape=(width==32,height==32,num_cell)))
    
    model.add(layers.Conv2D(32,(3,3),padding="same",activation="relu"))
    model.add(layers.MaxPooling2D()) 
    model.add(layers.Dropout(0.25))
    model.add(layers.Conv2D(64,(3,3),padding="same",activation="relu"))
    model.add(layers.MaxPooling2D()) 
    model.add(layers.Dropout(0.50))
    model.add(layers.Conv2D(128,(3,3),padding="same",activation="relu"))
    model.add(layers.MaxPooling2D())  
    model.add(layers.Flatten())
    model.add(layers.Dropout(0.50))
    model.add(layers.Dense(256,activation="relu"))
    model.add(layers.Dense(num_classes,activation="softmax"))
    model.summary()   
    model.compile(optimizer="adam",
                  loss=loss_function,metrics=["acc"])     
    return model

def train_model(model, epochs, batch_size):
    history = model.fit(train_gen, 
          epochs=epochs, 
          batch_size=batch_size,
          validation_data=test_gen,
          validation_freq=1)
    return history

def loss_acc_graph(history,suptitle):
    epoklar = range(1,len(historyList[0]["loss"])+1)
    
    fig,axx = plt.subplots(1,2,figsize=(18,6))
    
    colors = ["yellow","blue","black"]
    
    for i,history in enumerate(historyList):
        axx[0].plot(epoklar,history["loss"],label="Training " + aciklamalar[i],linestyle="--",color=colors[i])
        axx[0].plot(epoklar,history["val_"],label="Validation " + aciklamalar[i],color=colors[i],alpha=0.8)
        
    axx[0].set_title("Loss Comprasion")
    axx[0].set_xlabel("Epoklar")
    axx[0].set_ylabel("Loss Values")
    axx[0].legend()
  
    for i,history in enumerate(historyList):
        axx[1].plot(epoklar,history["acc"],label="Training " + aciklamalar[i],linestyle="--",color=colors[i])
        axx[1].plot(epoklar,history["val_acc"],label="Validation " + aciklamalar[i],color=colors[i],alpha=0.8)
    axx[1].set_title("Accuracy Comprasion")
    axx[1].set_xlabel("Epoklar")
    axx[1].set_ylabel("Accuracy Values")
    axx[1].legend()
    
    fig.suptitle("-".join(aciklamalar) + " Comprasion",fontsize=15,color="red")

    plt.show()

def loss_acc_graph_for_traing_test_data(history):
    plt.figure(0)
    plt.plot(history.history['acc'],'yellow')
    plt.plot(history.history['val_acc'],'blue')
    plt.xticks(np.arange(0, 11, 2.0))
    plt.rcParams['figure.figsize'] = (8, 6)
    plt.xlabel("Num of Epochs")
    plt.ylabel("Accuracy")
    plt.title("Training Accuracy vs Validation Accuracy")
    plt.legend(['train','validation'])
    plt.figure(1)
    plt.plot(history.history['loss'],'yellow')
    plt.plot(history.history['val_loss'],'blue')
    plt.xticks(np.arange(0, 11, 2.0))
    plt.rcParams['figure.figsize'] = (8, 6)
    plt.xlabel("Num of Epochs")
    plt.ylabel("Loss")
    plt.title("Training Loss vs Validation Loss")
    plt.legend(['train','validation'])

model = create_model("categorical_crossentropy")
history = train_model(model, 34, 50)

loss_acc_graph_for_traing_test_data(history)

import seaborn as sns

Predictions = model.predict(test_gen, test_gen.samples // 50)
predictions = np.argmax(Predictions, axis=1)

print(confusion_matrix(test_gen.classes, predictions))
cm = confusion_matrix(test_gen.classes, predictions)
plt.figure(figsize=(20, 10), dpi=80, facecolor='w', edgecolor='k')
ax = sns.heatmap(cm, cmap='Greens', annot=True, fmt='d', xticklabels=class_names, yticklabels=class_names)
plt.title("Cifar100 Dataset")
plt.xlabel('Prediction')
plt.ylabel('Truth')
plt.show(ax)

import tensorflow as tf
from keras.utils.vis_utils import plot_model

model_dir = veriseti_path + "cifar100_model"
model.save(model_dir, save_format='h5')
os.listdir(veriseti_path)
pretrained_model = tf.keras.models.load_model(model_dir)

#Check its architecture
plot_model(pretrained_model, to_file=veriseti_path + "model_plot.png", show_shapes=True, show_layer_names=True)