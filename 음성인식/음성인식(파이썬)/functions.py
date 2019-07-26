import sys
import operator
import numpy as np
import wave
import matplotlib.pyplot as plt

#wavegraph(파동그래프) 이미지 저장 여부
#freqeuncygraph(주파수그래프) 이미지 저장 여부
WGsave=False
FGsave=True

class VoiceRecognition:

    #wave파일의 음성에 대한 값 추출
    def getOriginalWaveValue(self, Filename):
        
        if not Filename.endswith(".wav"):
            Filename = Filename + ".wav"

        Wavefile = wave.open(Filename, 'r')
        signal = Wavefile.readframes(-1)
        signal = np.fromstring(signal, 'Int16')
        
        return signal.tolist()
    
    #파동그래프 출력
    def printWaveGraph(self, list, title='WaveGraph'):
        plt.figure(1)
        g = plt.subplot(111)
        g.set_xlabel('Time')
        g.set_ylabel('amplitude')
        plt.title(title)
        plt.plot(list, linewidth=1)
        if WGsave==True:
            plt.savefig(title+'.png')
        plt.show()

    #정규화 
    def normalization(self, list):
        maxvalue=0
        for i in range(len(list)):
            scanvalue=list[i]
            if maxvalue < abs(scanvalue):
                maxvalue=abs(scanvalue)

        normalized_graph=[]

        for i in range(len(list)):
            normalized_graph.append(list[i]/maxvalue)

        return normalized_graph

    #그래프 절대값 화 (아래로 내리기)
    def printAbsoluteGraph(self, list):
        absoluted_graph=[]
        for i in range(len(list)):
            absoluted_graph.append(abs(list[i]))

        return absoluted_graph

    #잡음 제거
    def removeNoiseGraph(self, absoluteGraph, originalGraph):
        #threshold
        sth=0.05

        #잡음을 제거한 graph index
        minTime=0
        maxTime=len(absoluteGraph)-1
        
        while absoluteGraph[minTime] < sth:
            minTime=minTime+1
        
        while absoluteGraph[maxTime] < sth:
            maxTime=maxTime-1

        realVoiceGraph=[]

        for i in range(minTime,maxTime):
            realVoiceGraph.append(originalGraph[i])

        return realVoiceGraph

    #푸리에변환 그래프 출력
    def printFTGraph(self, list, title='Furier Transform Graph'):
        plt.figure(1)
        FT = plt.subplot(111)
        #FT.set_xscale('log')
        #FT.set_yscale('log')
        FT.set_xlabel('Hz')
        FT.set_ylabel('| amplitude | (log10)')
        plt.title(title)
        plt.plot(list, linewidth=1)#AUDIO_DATA linewidth=1
        if FGsave==True:
            plt.savefig(title+'.png')
        plt.show()
        

    #푸리에 변환하기
    def generateFT(self, realVoiceGraph, Min=0, Max=0):
        extractGraph=[]

        
        if Min!=0 | Max!=0:
            for i in range(Min,Max):
                extractGraph.append(realVoiceGraph[i])
        else:
            for i in range(len(realVoiceGraph)):
                extractGraph.append(realVoiceGraph[i])
        #calculate=1000*abs(np.fft.rfft(extractGraph))
        calculate=np.log10(1000*abs(np.fft.rfft(extractGraph)))    #np.fft.rfft  np.fft.fftshift  
        FTGraph=calculate.tolist()

        return FTGraph






















    





            
