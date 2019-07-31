#-*- coding:utf-8 -*-
import os

img_path1="/home/lj/cy/openpose/piano/test_piano/res/line_white/"
img_path2 = "/home/lj/cy/openpose/piano/test_piano/res/test_background/"
img_list1=[os.path.join(img_path1,x) for x in os.listdir(img_path1)
            if x.endswith(".jpg")]
img_list2=[os.path.join(img_path2,x) for x in os.listdir(img_path2)
            if x.endswith(".jpg")]     
for img in img_list1:
    os.remove(img)

for img in img_list2:
    os.remove(img)