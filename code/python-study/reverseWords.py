def reversWords(input):
    inputWords = input.split(' ')
    inputWords = inputWords[-1::-1];
    output = ' '.join(inputWords)
    return output

#print(__name__)
if __name__ == '__main__':
    input = 'i like runoob'
    rw = reversWords(input)
    print(rw)

