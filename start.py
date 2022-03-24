import sys
import re

filename = sys.argv[1]
indent_re = re.compile(R"^([\s\t]+)")

with open(filename, 'r+') as file:
    content = file.readlines()
    final = []

    keep_lines_flag = True
    for line in content:
        stripped = line.strip()
        if stripped == "// SOLUTION":
            if not keep_lines_flag:
                raise Exception("wrong start solution section")
            keep_lines_flag = False
            final.append(line)
            match = indent_re.match(line)
            indent = match[0]
            final.append(f"{indent}// TODO: implement me\n")
        elif stripped == "// ~SOLUTION":
            if keep_lines_flag:
                raise Exception("wrong stop solution section")
            keep_lines_flag = True
            final.append(line)
        elif keep_lines_flag:
            final.append(line)

    file.seek(0)
    file.writelines(final)
    file.truncate()
