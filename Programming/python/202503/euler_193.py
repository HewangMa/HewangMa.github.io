import math, functools, time


def timing_decorator(func):
    """计算函数执行时间的装饰器"""

    @functools.wraps(func)
    def wrapper(*args, **kwargs):
        start_time = time.perf_counter()  # 高精度计时
        result = func(*args, **kwargs)
        end_time = time.perf_counter()
        elapsed_time = end_time - start_time
        print(f"Function '{func.__name__}' executed in {elapsed_time:.6f} seconds")
        return result

    return wrapper


def prime(n):
    if n <= 1:
        return False
    for i in range(2, int(math.sqrt(n)) + 1):
        if n % i == 0:
            return False
    return True


@timing_decorator
def gen_1(N):
    ret = []
    for i in range(N):
        if prime(i):
            ret.append(i)
    return ret


@timing_decorator
def solve1(N):
    ret = N
    for i in range(2, N):
        if prime(i):
            p = i * i
            if p > N:
                break
            ret -= N // p
    return ret


@timing_decorator
def prime_generator(N):
    # 生成N以内的质数
    primes = [2]
    yield primes[-1]
    i = 3
    while True:
        for p in primes:
            if i % p == 0:
                break
            if p * p > i:
                primes.append(i)
                yield primes[-1]
                break
        i += 1
        if i > N:
            break


@timing_decorator
def gen_2(N):
    return [_ for _ in prime_generator(N)]


@timing_decorator
def solve2(N):
    ret = N
    g = prime_generator(N)
    for i in g:
        p = i * i
        if p > N:
            break
        ret -= N // p
    return ret


if __name__ == "__main__":
    N =2**50
    print(f"N = {N}, ans = {solve2(N)}")
    # print(gen_2(100))
