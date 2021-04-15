# DATA COMPRESSION USING HUFFMAN CODING 
## INTRODUCTION 

This project implements data compression using huffman coding . i have chosen this project because due to the increased usage of internet , the amount of data that is generated is increasing at an exponential level , According to a recent estimate by idc the amount of data generated evey day in 2021 is 2500 petabytes. 



Build | Code Quality | Unity | Git Inspector| Code Coverage | Codacy
|---------:|------------:|-------------:|-----------:|----------------:|----------------:|
| [![C/C++ CI - Build Status](https://github.com/joydeep2899/260212_miniproject/actions/workflows/c-cpp.yml/badge.svg?branch=main&event=push)](https://github.com/joydeep2899/260212_miniproject/actions/workflows/c-cpp.yml) [![C/C++ CI WINDOWS- Build Status](https://github.com/joydeep2899/260212_miniproject/actions/workflows/windows.yml/badge.svg?branch=main&event=push)](https://github.com/joydeep2899/260212_miniproject/actions/workflows/windows.yml) | [![Code Quality - Static Code - Cppcheck](https://github.com/joydeep2899/260212_miniproject/actions/workflows/arc-cppcheck.yml/badge.svg?branch=main&event=push ) ](https://github.com/joydeep2899/260212_miniproject/actions/workflows/arc-cppcheck.yml) [![CodeQuality Dynamic Code Analysis Valgrind](https://github.com/joydeep2899/260212_miniproject/actions/workflows/arc-dynamic-code-quality.yml/badge.svg?branch=main&event=push)](https://github.com/joydeep2899/260212_miniproject/actions/workflows/arc-dynamic-code-quality.yml)| [![Unit Testing - Unity](https://github.com/joydeep2899/260212_miniproject/actions/workflows/arc-unity.yml/badge.svg?branch=main&event=push)](https://github.com/joydeep2899/260212_miniproject/actions/workflows/arc-unity.yml)   |   [![Contribution Check - Git Inspector](https://github.com/joydeep2899/260212_miniproject/actions/workflows/arc-gitinspector.yml/badge.svg?branch=main&event=push)](https://github.com/joydeep2899/260212_miniproject/actions/workflows/arc-gitinspector.yml)|   [![CI-Coverage](https://github.com/joydeep2899/260212_miniproject/actions/workflows/arc-code-coverage.yml/badge.svg?branch=main&event=push)](https://github.com/joydeep2899/260212_miniproject/actions/workflows/arc-code-coverage.yml) |    [![Codacy Badge](https://app.codacy.com/project/badge/Grade/373088c121f7423695121e001e701408)](https://www.codacy.com/gh/joydeep2899/260212_miniproject/dashboard?utm_source=github.com&amp;utm_medium=referral&amp;utm_content=joydeep2899/260212_miniproject&amp;utm_campaign=Badge_Grade)











## Folder Structure
Folder             | Description
-------------------| -----------------------------------------
`1_Requirements`   | Documents detailing requirements and research
`2_Architecture`         | Documents specifying design details
`3_Implementation` | All code and documentation
`4_Test_plan and output`      | Documents with test plans and procedures
`5_Report`      | Documents containing project report
`6_Images and videos `      | Images and videos related to project 
`7_Other`      | other miscellaneous files 

## Contributors List and Summary

SF Id. |  Name   |    Features    | Issuess Raised |Issues Resolved|No Test Cases|Test Case Pass
-------|---------|----------------|----------------|---------------|-------------|--------------
`260212` | Joydeep Ghosh  | 1,2,3,4,5,6  | 3     | 3   |1   |1    
   
## List  Of Features 
| Feature Id | Feature |
| -----------:|---------:|
|1| insert data into heapnodes |
|2| build minheap from heapnodes |
|3| insert heapnodes  into minheap |
|4| build huffman tree from minheap |
|5| print huffman codes on terminal |
|6| after execution of program the dynamically allocated memory is freed |



## Challenges Faced and How Was It Overcome
| No. | Challenge | Solution
|-----|-----------|--------
|1. | Code Crashed without any error message (Segmentation Fault) | valgrind helped find that minheap address was not being returned 
|2. | huffman tree was not getting built correctly | Implemented minheap |
|3. | minheap was not getting created directly from array | implemented heapnode data structure 
|4. | huffman tree was not getting printed on screen  | wrote printhuffman code to traverse the huffman tree and print huffman codes for each leaf node 
|5. | code coverage was not 100%  |  gcov helped find variable status was not intialised but not used and therefore it was deleted 
