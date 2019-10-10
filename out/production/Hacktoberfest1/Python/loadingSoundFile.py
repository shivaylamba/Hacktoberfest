#class DataCollection:
import os
import struct
import matplotlib.pyplot as plt
import IPython.display as ipd
import pandas as pd
import numpy as np
import librosa
def path_class(data,filename):
	excerpt = data[data['slice_file_name'] == filename]
	path_name = os.path.join('UrbanSound8K/audio', 'fold'+str(excerpt.fold.values[0]), filename)
	return path_name, excerpt['class'].values[0]

def wav_plotter(full_path, class_label):   
	rate, wav_sample = wav.read(full_path)
	wave_file = open(full_path,"rb")
	riff_fmt = wave_file.read(36)
	bit_depth_string = riff_fmt[-2:]
	bit_depth = struct.unpack("H",bit_depth_string)[0]
	print('sampling rate: ',rate,'Hz')
	print('bit depth: ',bit_depth)
	print('number of channels: ',wav_sample.shape[1])
	print('duration: ',wav_sample.shape[0]/rate,' second')
	print('number of samples: ',len(wav_sample))
	print('class: ',class_label)
	plt.figure(figsize=(12, 4))
	plt.plot(wav_sample) 
	return ipd.Audio(full_path)
'''
def sound_to_mat(fullpath):
	try:
		librosa_load, librosa_sampling_rate = librosa.load(fullpath, res_type='kaiser_fast')
		mfccs = np.mean(librosa.feature.mfcc(y= librosa_load, sr= librosa_sampling_rate, n_mfcc=40).T,axis=0) 
   	except Exception as e:
      		
		print("Error encountered while parsing file: ", file)
      	return None, None
	
	feature = mfccs
    label = row.Class
 
   	return [feature, label]
'''

def wav_fmt_parser(file_name):
	full_path, _ = path_class(file_name)
	wave_file = open(full_path,"rb")
	riff_fmt = wave_file.read(36)
	n_channels_string = riff_fmt[22:24]
	n_channels = struct.unpack("H",n_channels_string)[0]
	s_rate_string = riff_fmt[24:28]
	s_rate = struct.unpack("I",s_rate_string)[0]
	bit_depth_string = riff_fmt[-2:]
	bit_depth = struct.unpack("H",bit_depth_string)[0]
	return (n_channels,s_rate,bit_depth)


'''
def parser(row):
	try:
		X, sample_rate = librosa.load(fullpath, res_type='kaiser_fast')
        mfccs = np.mean(librosa.feature.melspectrogram(y=X, sr=sample_rate).T,axis=0)
    except Exception :
    	print("Error encountered while parsing file: ", file)
    	mfccs,class_id = None, None
    feature = mfccs
    label = class_id
    return feature, label
'''
