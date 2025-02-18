import string

def count_chars(word):
    char_count = {}

    word = [char for char in word.lower() if char in string.ascii_lowercase]
    
    for char in word:
        if char in char_count:
            char_count[char] += 1
        else:
            char_count[char] = 1
    return char_count


user_input = input("Nhập một từ hoặc câu: ")


result = count_chars(user_input)
print("Số lượng các ký tự là:", result)
