import sys
import operator
import numpy as np
import wave
import matplotlib.pyplot as plt
import functions

class testDecisionTree:

    def generate_0(self,list):
        #임계점
        sth=4.5
        #그래프 최댓값
        Max=0
        #decision tree
        going=0
        for i in list:
             if Max < i:
                 Max=i
        #print(Max)
        if sth<Max:
            going=1
        else:
            going=2
  
        return going

    def generate_1(self,list):
        sumall=0
        sum1=0
        sum2=0
        going=0
        for i in range(0,len(list)):
            if i < len(list)//4:
                sum1+=list[i]
                
            else:
                sum2+=list[i]
                
            sumall+=list[i]
        
        rate1=sum1/sumall*100
        rate2=sum2/sumall*100
        #print(rate1, rate2)
        if rate1<29:
            going=1
        else:
            going=2

        #print(going)
        return going



    def generate_11(self,list):
        sumall=0
        sum1=0
        sum2=0
        sum3=0
        going=0
        for i in range(0,len(list)):
            if i < len(list)//3:
                sum1+=list[i]
                
            elif i<len(list)*2//3:
                sum2+=list[i]

            else:
                sum3+=list[i]
            sumall+=list[i]

            
        rate1=sum1/sumall*100
        rate2=sum2/sumall*100
        rate3=sum3/sumall*100

        #print(rate1, rate2, rate3)

        if rate1<37:
            going=1
        else:
            going=2

        return going

    def generate_111(self,list):
        sumall=0
        sum1=0
        sum2=0
        going=0
        for i in range(0,len(list)):
            if i < len(list)//2:
                sum1+=list[i]

            else:
                sum2+=list[i]

            sumall+=list[i]

            
        rate1=sum1/sumall*100
        rate2=sum2/sumall*100

        #print(rate1, rate2)

        if rate2<40:
            going=1
        else:
            going=2
        return going

    def generate_12(self,list):
        sumall=0
        sum1=0
        sum2=0
        
        going=0
        for i in range(0,len(list)//4):
            if i < len(list)//8:
                sum1+=list[i]

            else:
                sum2+=list[i]

            sumall+=list[i]

        rate1=sum1/sumall*100
        rate2=sum2/sumall*100
        
        print(rate1, rate2)

        if rate2<45:
            going=1
        else:
            going=2
            
        return going

    def generate_2(self,list):
        sumall=0
        sum1=0
        sum2=0
        sum3=0
        sum4=0
        going=0
        for i in range(len(list)):
            if i < len(list)//4:
                sum1+=list[i]
                
            elif i<len(list)*2//4:
                sum2+=list[i]

            elif i<len(list)*3//4:
                sum3+=list[i]
                
            else:
                sum4+=list[i]
            sumall+=list[i]        

        rate1=sum1/sumall*100
        rate2=sum2/sumall*100
        rate3=sum3/sumall*100
        rate4=sum4/sumall*100

        #print(rate1, rate2, rate3, rate4)

        if rate2>26:
            going=2
        elif rate2>24.5:
            going=1
        elif rate1>31:
            going=4
        else:
            going=3
            
        #print(going)
        return going

    def generate_21(self, list):
        sumall=0
        sum1=0
        sum2=0
        sum3=0
        sum4=0
        going=0
        for i in range(len(list)):
            if i < len(list)//4:
                sum1+=list[i]
                
            elif i<len(list)*2//4:
                sum2+=list[i]

            elif i<len(list)*3//4:
                sum3+=list[i]
                
            else:
                sum4+=list[i]
            sumall+=list[i]        

        rate1=sum1/sumall*100
        rate2=sum2/sumall*100
        rate3=sum3/sumall*100
        rate4=sum4/sumall*100

        #print(rate1, rate2,rate3,rate4)

        if rate2<23.5:
            going=1
        else:
            going=2
        
        return going
