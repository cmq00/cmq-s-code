#!/usr/bin/env python3
#_*_coding:utf8_*_

def display(char):

    character = {
        'A' : ['2 6#2 ', '2 1#4 1#2 ', '2 5#2 ', '2 1#4 1#2 ', '2 1#4 1#2 '],
        'B' : ['2 6#2 ', '2 1#4 1#2 ', '2 5#3 ', '2 1#4 1#', '2 5#2 ']
    }
    
    for line in character[char]:
        for seq in range(0, len(line) - 2, 2):
            repeat = int(line[seq])
            char = line[seq + 1]
    
            for i in range(repeat):
                print('%c' % char, end='')
    
        print('\n', end = '')
    
    print('')


if __name__ == '__main__':

    for name in 'AB':
        display(name)
