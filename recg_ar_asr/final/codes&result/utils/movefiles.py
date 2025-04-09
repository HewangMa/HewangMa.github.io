import os, random, shutil


def move_randomly_from_A_to_B(folder_a, folder_b, ratio=0.5):
    files = os.listdir(folder_a)
    total_num = len(files)
    moved = [0] * total_num
    move_num = int(total_num * ratio)
    for i in range(move_num):
        idx_to_move = random.randint(0, total_num - 1)
        while moved[idx_to_move] == 1:
            idx_to_move = random.randint(0, total_num - 1)
        moved[idx_to_move] = 1
        file_to_move = files[idx_to_move]
        shutil.move(
            os.path.join(folder_a, file_to_move), os.path.join(folder_b, file_to_move)
        )


def run():
    data_path = os.path.dirname(os.path.dirname(__file__))
    data_path = os.path.join(data_path, "data", "sr_data_whole", "train")
    for speaker in os.listdir(data_path):
        src = os.path.join(data_path, speaker)
        des = os.path.join(os.path.dirname(data_path), "test", speaker)
        os.makedirs(des)
        print(f" randomly {src} ====>>> {des}")
        move_randomly_from_A_to_B(src, des)


if __name__ == "__main__":
    run()
