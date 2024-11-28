from cyaron import *
import random as rd

for cas in range(1, 11):
    io = IO(file_prefix="rotate", data_id=cas, input_suffix=".in", output_suffix=".ans")
    n = rd.randint(2, 100)
    io.input_writeln(n)
    for i in range(n):
        l = ''.join(rd.choice(['0', '1']) for i in range(n))
        io.input_writeln(l)
    io.output_gen("rotate")