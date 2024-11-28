from cyaron import *
import random as rd
import json

def solution(N, rain):
    level = [0] * (10 ** 6 + 1)
    for i in rain:
        level[i] += 1

    days = 0
    for i in range(len(level) - 1, 0, -1):
        days += level[i]
        if days >= i:
            return i
            break

config = {
    "subtask": [
        {
            "N": [1, 1000],
            "r": [1, 1000],
            "number": 12
        },
        {
            "N": [1, 10 ** 6],
            "r": [1, 10 ** 6],
            "number": 8
        }
    ]
}

idx = 0

for sub in config["subtask"]:
    for cas in range(sub["number"]):
        N = sub["N"][1]
        r = [rd.randint(sub["r"][0], sub["r"][1]) for i in range(N)]
        idx += 1
        io = IO(file_prefix="rain", data_id=idx, input_suffix=".in", output_suffix=".ans")
        io.input_writeln(N)
        io.input_writeln(r)
        ans = solution(N, r)
        io.output_writeln(ans)
    