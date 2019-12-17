# Is prime?
入力された数が素数かどうかを判定します。  
判定器にはミラーラビン素数判定法を用いています。https://en.wikipedia.org/wiki/Miller%E2%80%93Rabin_primality_test  
デフォルトでは100回判定されます。

## Install
多倍長整数の演算にはGNU Multi Precision Arithmetic Library(https://gmplib.org/ )を使っています。  
macの場合は
```
$ brew insatll gmp
```  
などでインストールできます。Linuxの場合は上記サイトからアーカイブをDLし、makeでインストールできます。  

あとはmakeしてください。

## Usage
### Primality test
以下のようにコマンドラインから入力します。  
```
$ ./isprime.out 89
```
素数ならその数をそのまま返し、そうでないなら何も返しません。
```
$ ./isprime.out 89
89
$ ./isprime.out 57
$
```
上のような感じになります。

### Enumerate
Primality testに一つオプションをつけることができます。オプションは整数で、正の数が入力された場合には正の方向に、負数の場合には負の方向に素数を絶対値の数だけ列挙します。0の場合は何も返しません。
```
$ ./isprime.out 1 25
2
3
5
7
11
13
17
19
23
29
31
37
41
43
47
53
59
61
67
71
73
79
83
89
97
$ ./isprime.out 100 -25
97
89
83
79
73
71
67
61
59
53
47
43
41
37
31
29
23
19
17
13
11
7
5
3
2
$
```
のような感じです。ある合成数nの次の素数が知りたければ、`./isprime.out n 1`と入力すれば表示されます。  
