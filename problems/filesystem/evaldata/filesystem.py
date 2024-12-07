def proc(route):
    ret = []
    for folder in route:
        if folder == '.':
            continue
        elif folder == '..':
            if len(ret) > 0:
                ret.pop()
        else:
            ret.append(folder)
    return ret

def Main():
    n = int(input())
    files = []
    for i in range(n):
        route = input().split('/')
        route = proc(route)
        new_route = '/'.join(route)
        files.append(new_route)
    T = int(input())
    for i in range(T):
        route = input().split('/')
        route = proc(route)
        new_route = '/'.join(route)
        if new_route in files:
            print('Yes')
        else:
            print('No')
            files.append(new_route)

if __name__ == '__main__':
    Main()