def proc(route):
    ret = []
    for folder in route:
        if folder == '.':
            continue
        elif folder == '..':
            if len(ret) > 0:
                ret.pop()
            else:
                raise ValueError('Invalid path')
        else:
            ret.append(folder)
    return ret

def Main(n, fcache, T, qcache):
    files = []
    ret = []
    for i in range(n):
        route = fcache[i].split('/')
        route = proc(route)
        new_route = '/'.join(route)
        files.append(new_route)
    for i in range(T):
        route = qcache[i].split('/')
        route = proc(route)
        new_route = '/'.join(route)
        if new_route in files:
            ret.append('Yes')
        else:
            files.append(new_route)
            ret.append('No')
    return ret
            

if __name__ == '__main__':
    n = int(input())
    files = [input() for _ in range(n)]
    T = int(input())
    querys = [input() for _ in range(T)]
    answer = Main(n, files, T, querys)
    for ans in answer:
        print(ans)