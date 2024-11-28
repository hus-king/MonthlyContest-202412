from cyaron import *
import random as rd

for cas in range(1, 21):
    io = IO(file_prefix = "ip", data_id = cas, input_suffix = ".in", output_suffix = ".ans")
    ip_number = [rd.randint(0, 255) for i in range(4)]
    ip = '.'.join(map(str, ip_number))
    io.input_writeln(ip)
    answer = ''.join(map(lambda x: bin(x)[2:].zfill(8), ip_number))
    io.output_writeln(answer)