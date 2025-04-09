import math

if __name__ == '__main__':
    line_cnt = 1
    current_largest = 0
    ans_line = 0
    with open('0099_base_exp.txt', 'r') as file:
        line = file.readline().strip()
        while line:
            nums = line.split(',')
            nums[0] = int(nums[0])
            nums[1] = int(nums[1])
            log_of_line = nums[1] * math.log(nums[0])
            if log_of_line > current_largest:
                print(line_cnt, nums[0], nums[1])
                current_largest = log_of_line
                ans_line = line_cnt
            line = file.readline().strip()
            line_cnt += 1
