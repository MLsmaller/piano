#-*- coding:utf-8 -*-

from __future__ import division
from __future__ import absolute_import
from __future__ import print_function

import cv2
import numpy
import argparse
import os

data_path = '//home/data/cy/projects/piano/video'

audio_txt = os.path.join(data_path, 'video1_crop.txt')
w_txt=os.path.join(data_path,'w_key.txt')
b_txt=os.path.join(data_path,'b_key.txt')
real_txt = os.path.join(data_path, 'real_video1.txt')
w_pressed_txt = os.path.join(data_path, 'pressed_w.txt')

black_num = [2, 5, 7, 10, 12, 14, 17, 19, 22, 24, 26, 29, 31, 34, 36, 38, 41, 43,
            46, 48, 50, 53, 55, 58, 60, 62, 65, 67, 70, 72, 74, 77, 79,82, 84, 86]
white_num = []
for i in range(1, 89):
    if i not in black_num:
        white_num.append(i)
print(white_num)

#----将cnn检测到的txt分为白键和黑键两个txt，白键范围是1-52，黑键是1-36
def white_black_txt(audio_txt, w_txt, b_txt):
    #------将cnn检测到的按键编号减去21,变为从1开始-------
    offset = 20
    with open(audio_txt, 'r') as f:
        lines = f.readlines()

    new_lines = []
    for i, line in enumerate(lines):
        temp_lines = []
        line = line.strip().split()
        for j, data in enumerate(line):
            if not (j == 2):
                temp_lines.append(data)
            else:
                temp_lines.append(str(int(data) - offset))
            
        new_lines.append(temp_lines)

    if os.path.exists(w_txt):
        os.remove(w_txt)
    if os.path.exists(b_txt):
        os.remove(b_txt)

    w_out = open(w_txt, 'w')
    b_out = open(b_txt, 'w')

    for line in new_lines:
        #line = line.strip().split()
        index = int(line[2])    #line[2]是一个字符串类型,需要转换为int,不然肯定不在list中
        if index in black_num:
            Bkey_index = black_num.index(index) + 1  #查看元素在list中的索引
            line[2] = str(Bkey_index)    
            for data in line:
                b_out.write('{} '.format(data))
            b_out.write('\n')
        else:
            Wkey_index = white_num.index(index) + 1 #找到原来txt中白键的编号在white_num中的位置,然后变为1-52按键范围(与标签数据对齐)
            line[2] = str(Wkey_index)
            for data in line:
                w_out.write('{} '.format(data))
            w_out.write('\n')
    b_out.close()
    w_out.close()
    print('the txt file has done')

#------将自己标的按键转换为检测onset的文件,就是只记录被按下的键和按键的起始时间,以便比较
def read_realData(real_txt, pressed_txt):
    with open(real_txt, 'r') as f:
        lines = f.readlines()
    filenames = []
    times = []
    keys = []
    
    for i, line in enumerate(lines):
        key = []
        line = line.strip().split()
        filenames.append(line[0])
        times.append(float(line[1]))
        for j in range(2, len(line)):
            key.append(int(line[j]))
        keys.append(key)
        if (i > 208):
            break
    #print(len(filenames), len(times), len(keys))

    if os.path.exists(pressed_txt):
        os.remove(pressed_txt)
    fout = open(pressed_txt, 'w')
    #pressed_keys = []
    #----对于两个list看他们的相同/不同元素可以转换为集合来求交并集-----
    for i in range(1,len(filenames)):
        current_keys = set(keys[i])
        last_keys = set(keys[i - 1])
        set1 = list(current_keys.symmetric_difference(last_keys))
        set2 = set1[:]  #python如何直接set2=set1这样复制的话改变其中一个两个都会变,因为其指向的都是一样的
                        #使用new=old[:]的话会创建新的列表,不会影响原来的
        if (0 in set2):
            set2.remove(0)

        if (len(set1) > 0):
            if 0 in set1:
                set1.remove(0)
            for w_key in set1:
                if w_key in list(last_keys):
                    set2.remove(w_key)   #不能set1.remove(),这样的话set1就改变了,下次for in 循环不会进行

            if len(set2) > 0:
                fout.write('{} '.format(filenames[i]))
                fout.write('{} '.format(times[i]))
                for pressed_key in set2:
                    fout.write('{} '.format(pressed_key))
                fout.write('\n')

        #print(len(set1))

def count_acuuracy(w_pressed_txt, w_txt):
    with open(w_txt, 'r') as f:
        lines1 = f.readlines()
    audio_keys = []
    audio_times = []
    audio_res = []
    for line in lines1:
        line = line.strip().split()
        audio_keys.append(int(line[2]))
        audio_times.append(float(line[0]))
        audio_res.append((float(line[0]), int(line[2])))
    audio_res = sorted(audio_res, key=lambda x: (x[0],x[1]))   #对List中元素先按照第一个排序再按照第二个排序
    #print(audio_res)

    with open(w_pressed_txt, 'r') as f:
        lines2 = f.readlines()
    #real_keys = []
    #real_times = []
    real_res = []
    for line in lines2:
        line = line.strip().split()
        keys = []
        for i in range(2, len(line)):
            keys.append(int(line[i]))
        for key in keys:
            real_res.append((float(line[1]), key))
    real_res = sorted(real_res, key=lambda x: (x[0],x[1]))
    
    #print(real_res)
    offset = 0.1
    right_keys = []
    for i, w_key in enumerate(real_res):
        cur_time = w_key[0]
        cur_key = w_key[1]
        for audio_key in audio_res:
            if (abs(cur_time - audio_key[0]) < offset):
                if (cur_key == audio_key[1]):
                    right_keys.append(audio_key)
                #print(audio_key)
    print('the right keys is {}'.format(right_keys))
    print('the total keys is {}'.format(len(real_res)))
    print('the number of correct keys is {}'.format(len(right_keys)))
    print('召回率为: {}'.format(len(right_keys) / len(real_res)))

if __name__ == '__main__':
    print(len(white_num))
    ToStop = 208   #先检验一下现在标的这些怎么样
    #white_black_txt(audio_txt, w_txt, b_txt)
    #read_realData(real_txt, w_pressed_txt)
    count_acuuracy(w_pressed_txt, w_txt)
    
    



#-----下午先进行它和真实数据的比较试一下兄弟---