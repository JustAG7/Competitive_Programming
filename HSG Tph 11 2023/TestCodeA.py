import os

def main():
    folder_prefix = "TEST"
    file_prefix = "newyear"
    sol_file = "D:\\C++\\Competitive_Programming\\HSG Tph 11 2023\\sol.exe"  # Replace this with the actual path of your sol executable

    for i in range(1, 21):
        folder_name = f"{folder_prefix}{i:02}"
        newyear_inp = os.path.join(folder_name, f"{file_prefix}.inp")
        newyear_out = os.path.join(folder_name, f"{file_prefix}.out")

        # Tạo thư mục
        try:
            os.makedirs(folder_name)
        except OSError:
            print(f"Không thể tạo thư mục: {folder_name}")
            continue

        # Tạo và ghi input vào file .inp
        with open(newyear_inp, "w", encoding="utf-8") as inp_file:
            inp_file.write(f"Input content for {folder_name}\n")

        # Chạy sol.cpp và ghi output vào file .out
        run_command = f"g++ {sol_file} -o sol && {sol_file} >> {newyear_out}"
        exit_code = os.system(run_command)

        if exit_code != 0:
            print(f"Lỗi khi chạy sol.cpp trong thư mục: {folder_name}")
            with open(newyear_out, "a", encoding="utf-8") as out_file:
                out_file.write("Lỗi khi chạy sol.cpp\n")

if __name__ == "__main__":
    main()
