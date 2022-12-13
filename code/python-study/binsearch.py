#!/usr/bin/env python
#_*_coding:utf8_*_



class Student(object):

    def __init__(self, no, score):

        self.no = no
        self.score = score

    def __lt__(self, score):

        return self.score  < score

    def __gt__(self, score):

        return self.score > score


class StudentByNo(Student):

    def __lt__(self, no):

        return self.no < no

    def __gt__(self, no):

        return self.no > no



def binsearch(array, num):

    low, high = 0, len(array) - 1

    while low <= high:

        mid = int((low + high) / 2)
        if array[mid] < num:
            low = mid + 1
        elif array[mid] > num:
            high = mid - 1

        else:
            return mid

    return -1


if __name__ == '__main__':
   
    #print(binsearch([1, 2, 7, 8, 9, 10, 13, 17], 7))

    student = list()
    for i in range(7):
        obj = StudentByNo(i, 90 + i)

        student.append(obj)

    for obj in student:
        print(obj.no, obj.score)

    #result = binsearch(student, 91)
    print('result:')
    result = binsearch(student, 2)
    if result != -1:
        print(student[result].no, student[result].score)
    
