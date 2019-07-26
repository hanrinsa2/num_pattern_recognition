import functions
import test
import numpy as np
import pygame

#생성자 
functions=functions.VoiceRecognition()
test=test.testDecisionTree()


while(1):
    file=input("filename(q입력시 종료) : ")
    if file=='q':
        break

    print("File : ", file, ".wav")

    sound=file
    if not sound.endswith(".wav"):
        sound=sound+".wav"

    pygame.mixer.init()
    pygame.mixer.music.load(sound)
    pygame.mixer.music.play()
        
    #file = 'nine'
    #print("File : ", file, ".wav")

    voiceValue=functions.getOriginalWaveValue(file)
    #functions.printWaveGraph(voiceValue) #기본 그래프 출력

    normalgraph=functions.normalization(voiceValue)
    #functions.printWaveGraph(normalgraph) #정규화된 기본 그래프 출력

    absoluted=functions.printAbsoluteGraph(normalgraph)
    #functions.printWaveGraph(absoluted) #정규화된 그래프를 절대값화 시킴

    realvoicegraph=functions.removeNoiseGraph(absoluted,normalgraph)
    #functions.printWaveGraph(realvoicegraph) # 정규화된 기본 그래프의 잡음을 제거

    ftgraph_0=functions.generateFT(realvoicegraph,0,len(realvoicegraph)//5)# 0~1/5 사이 frequency analysis 실행
    ftgraph_1=functions.generateFT(realvoicegraph,len(realvoicegraph)*1//5,len(realvoicegraph)*2//5)# 1/5~2/5 사이 frequency analysis 실행 
    ftgraph_2=functions.generateFT(realvoicegraph,len(realvoicegraph)*2//5,len(realvoicegraph)*3//5)# 2/5~3/5 사이 frequency analysis 실행
    ftgraph_3=functions.generateFT(realvoicegraph,len(realvoicegraph)*3//5,len(realvoicegraph)*4//5)# 3/5~4/5 사이 frequency analysis 실행 
    ftgraph_4=functions.generateFT(realvoicegraph,len(realvoicegraph)*4//5,len(realvoicegraph))# 4/5~끝 사이 frequency analysis 실행
    ftgraph_all=functions.generateFT(realvoicegraph,0,len(realvoicegraph)*13//20)#전체 
    
    functions.printFTGraph(ftgraph_4)#푸리에 변환 그래프 출력 

    #test.generate_0(ftgraph_0)
    #test.generate_1(ftgraph_all)
    #test.generate_11(ftgraph_4)
    #test.generate_12(ftgraph_all)
    #test.generate_111(ftgraph_2)
    #test.generate_2(ftgraph_4)
    #test.generate_21(ftgraph_1)

    Root=test.generate_0(ftgraph_0)#123456789

    if Root==1:
        node1=test.generate_1(ftgraph_all)#01256

        if node1==1:
            node11=test.generate_11(ftgraph_4)#016

            if node11==1:#1
                print("숫자 : 1")

            else:
                node111=test.generate_111(ftgraph_2)#06

                if node111==1:
                    print("숫자 : 0")
                else:
                    print("숫자 : 6")

                    
        else:
            node12=test.generate_12(ftgraph_all)#25

            if node12==1:
                print("숫자 : 2")
            else:
                print("숫자 : 5")
                

    elif Root==2:
        node2=test.generate_2(ftgraph_4)#34789

        if node2==1:
            print("숫자 : 3")
        elif node2==2:
            print("숫자 : 4")

        elif node2==3:
            node21=test.generate_21(ftgraph_1)#78
            if node21==1:
                print("숫자 : 7")
            else:
                print("숫자 : 8")
        else:
            print("숫자 : 9")




















        
    
