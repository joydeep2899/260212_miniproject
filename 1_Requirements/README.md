# REQUIREMENTS
## INTRODUCTION 

This project implements data compression using huffman coding . i have chosen this project because due to the increased usage of internet , the amount of data that is generated is increasing at an exponential level , According to a recent estimate by idc the amount of data generated evey day in 2021 is 2500 petabytes. 


## RESEARCH 

1 https://www.dihuni.com/2020/04/10/every-day-big-data-statistics-2-5-quintillion-bytes-of-data-created-daily/

2 https://websitesetup.org/news/internet-facts-stats 

3 https://www.cisco.com/c/en/us/solutions/collateral/executive-perspectives/annual-internet-report/white-paper-c11-741490.html

4 https://www.statista.com/statistics/617136/digital-population-worldwide

## SWOT ANALYSIS 

 <img src="swot analysis.png" alt="swot analysis "/>








## 4W'S AND 1H'S


 ### WHO 
     this system can be used by developers who are developing chat applications , text editors to compress the whole text content to consume less space and reduce the load on the system 

 ### WHAT 
     many developers and system designers face stiff task when trying to reduce the data from their applications . this increases the cost of maintaing the system since this requires additonal storage and processing power on servers. this leading to cost overruns 

 ### WHERE 
        developers all over the world face this issue when trying to develop new applications .
 ### WHEN
         developers face this issue all the time while developing new chat applications . system designers face this issue while trying to scale the backend of their applications and while creating new system architectures which can support the increased data  from scaling up.
 ### HOW 
       since there has been an increase in the number of users of chat applications and people using text on their phones . this issue has been created as a result of the increased usage of chat applications 



## HIGH LEVEL REQUIREMENTS 


| ID       | DESCRIPTION          | STATUS(IMPLEMENTED/FAILURE)  |
| ------------- |:-------------:| -----:|
| 1      | SHOULD BE ABLE TO TAKE CHARACTER ARRAY  | IMPLEMENTED |
| 2     | SHOULD BE ABLE TO TAKE INTEGER FREQUENCY OF CHARACTERS      |   IMPLEMENTED |
| 3 | SHOULD BE ABLE TO BUILD HUFFMAN TREE       |    IMPLEMENTED |
| 4 | SHOULD BE ABLE TO BUILD MINHEAP      |    IMPLEMENTED |
## LOW LEVEL REQUIREMENTS 
| ID       | DESCRIPTION          | STATUS(IMPLEMENTED/FAILURE)  |
| ------------- |:-------------:| -----:|
| 1      | SHOULD BE ABLE TO MAKE HEAPNODES FROM CHARACTER ARRAY  | IMPLEMENTED |
| 2     | SHOULD BE ABLE TO INSERT HEAPNODE INTO MINHEAP      |   IMPLEMENTED |
| 3 | SHOULD BE ABLE TO HEAPIFY THE MINHEAP EVERYTIME REQUIRED      |    IMPLEMENTED |
| 4 | SHOULD BE ABLE TO PRINT THE HUFFMAN TREE  ON THE TERMINAL    |    IMPLEMENTED |