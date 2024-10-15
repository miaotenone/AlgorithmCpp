import os

HEAD = '''cmake_minimum_required(VERSION 3.17)
project(lc-cpp)

set(CMAKE_CXX_STANDARD 17)
add_definitions("-DKUN_DEBUG")
include_directories("src/utils")

'''


def update_cmake():
    file_list = []
    for root, dirs, files in os.walk("src"):
        if len(files) == 0:
            continue
        for f in files:
            file_list.append(root + os.sep + f)
    res = HEAD
    for i in sorted(file_list):
        if 'utils' in i:
            continue
        split = i.split(os.sep)
        name_ids = filter(lambda x: x != 'src', split)
        name = "_".join(name_ids).replace(".cpp", "")
        path = "/".join(split)
        code = f'add_executable({name} {path})\n'
        res += code
    with open('CMakeLists.txt', "w") as f:
        f.write(res)


if __name__ == '__main__':
    update_cmake()
