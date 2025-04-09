# 读取excel文件内容 并放在list中
excel_list = open("./vote_code_check/vote_code.txt", "r", encoding="utf-8").readlines()

# 读取word文件内容并放在list中
pdf_content = open("./vote_code_check/pdf_code2.txt", "r", encoding="utf-8").read()

start = 0
Total_length = len(pdf_content)
pdf_list = []
while start < Total_length:
    start = pdf_content.find("SZ", start)
    if start == -1:
        break
    one = pdf_content[start:start + 12]
    # print(f"start :{start},one: {one}")
    pdf_list.append(one)
    start += 12

print(f"pdf_list:{pdf_list}")
print(f"excel_list:{excel_list}")

print(f"excel_list length:{len(excel_list)}, pdf_list length: {len(pdf_list)}")

index = 0
while index < 94:
    if excel_list[index][0:-1] != pdf_list[index]:
        print(f"something wrong: index = {index}")
        break
    index += 1

if index == 94:
    print("all right")
