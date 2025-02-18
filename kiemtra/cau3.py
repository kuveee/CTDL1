import string
import os
import re


def word_count(file_path):
    word_count_dict = {}
    with open(file_path, 'r', encoding='utf-8') as file: 
        for line in file:
            line = line.lower()
            
            line = re.sub(r'[^\w\s]', '', line)
            
            words = line.split()
            
            for word in words:
                if len(word) > 1:  
                    if word in word_count_dict:
                        word_count_dict[word] += 1
                    else:
                        word_count_dict[word] = 1
                    
    return word_count_dict

file_path = r'D:\cdtl_sc\kiemtra\P1_data.txt'  

if os.path.exists(file_path):
    result = word_count(file_path)
    print(result)
else:
    print(f"File không tồn tại tại đường dẫn: {file_path}")
