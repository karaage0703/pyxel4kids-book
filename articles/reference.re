= Pyxelリファレンス

//lead{
この章では、Pyxelで使える命令の一覧と使い方を紹介します。
//}

== リファレンスとは

リファレンス（reference）とは、「参照」や「参考資料」という意味です。プログラミングにおけるリファレンスは、使える命令（関数やメソッド）の一覧と、その使い方をまとめたものです。

この章では、Pyxelで使える主な命令を紹介します。新しいゲームを作るときや、わからない命令があるときに、この章を参考にしてください。

より詳しい情報は、Pyxelの公式ドキュメント（https://github.com/kitao/pyxel）を参照してください。

== 基本的な命令

Pyxelの基本的な命令を紹介します。

=== 初期化と実行

//list[init_run][初期化と実行][python]{
# Pyxelの初期化
pyxel.init(width, height, title="タイトル", fps=30, quit_key=pyxel.KEY_ESCAPE)
# width: 画面の幅（ピクセル単位）
# height: 画面の高さ（ピクセル単位）
# title: ウィンドウのタイトル（省略可）
# fps: フレームレート（1秒あたりのフレーム数、省略可）
# quit_key: 終了キー（省略可）

# Pyxelの実行
pyxel.run(update, draw)
# update: 画面を更新する関数
# draw: 画面を描画する関数
//}

=== 入力

//list[input][入力][python]{
# キーが押されているかチェック
pyxel.btn(key)
# key: キーコード（例: pyxel.KEY_SPACE, pyxel.KEY_LEFT）
# 戻り値: キーが押されていればTrue、そうでなければFalse

# キーが押された瞬間をチェック
pyxel.btnp(key, hold=0, period=0)
# key: キーコード
# hold: キーを押し続けた時に、最初の入力を受け付けるまでの時間（省略可）
# period: キーを押し続けた時に、2回目以降の入力を受け付ける間隔（省略可）
# 戻り値: キーが押された瞬間であればTrue、そうでなければFalse

# マウスの位置を取得
pyxel.mouse_x  # マウスのX座標
pyxel.mouse_y  # マウスのY座標

# マウスボタンが押されているかチェック
pyxel.btn(button)
# button: ボタンコード（pyxel.MOUSE_LEFT, pyxel.MOUSE_RIGHT, pyxel.MOUSE_MIDDLE）
# 戻り値: ボタンが押されていればTrue、そうでなければFalse

# マウスボタンが押された瞬間をチェック
pyxel.btnp(button)
# button: ボタンコード
# 戻り値: ボタンが押された瞬間であればTrue、そうでなければFalse
//}

=== 描画

//list[drawing][描画][python]{
# 画面をクリア
pyxel.cls(col)
# col: 背景色（0-15）

# 点を描画
pyxel.pset(x, y, col)
# x, y: 点の座標
# col: 点の色（0-15）

# 線を描画
pyxel.line(x1, y1, x2, y2, col)
# x1, y1: 始点の座標
# x2, y2: 終点の座標
# col: 線の色（0-15）

# 四角形を描画（塗りつぶし）
pyxel.rect(x, y, w, h, col)
# x, y: 左上の座標
# w, h: 幅と高さ
# col: 四角形の色（0-15）

# 四角形を描画（枠のみ）
pyxel.rectb(x, y, w, h, col)
# x, y: 左上の座標
# w, h: 幅と高さ
# col: 枠の色（0-15）

# 円を描画（塗りつぶし）
pyxel.circ(x, y, r, col)
# x, y: 中心の座標
# r: 半径
# col: 円の色（0-15）

# 円を描画（枠のみ）
pyxel.circb(x, y, r, col)
# x, y: 中心の座標
# r: 半径
# col: 枠の色（0-15）

# 三角形を描画（塗りつぶし）
pyxel.tri(x1, y1, x2, y2, x3, y3, col)
# x1, y1: 1つ目の頂点の座標
# x2, y2: 2つ目の頂点の座標
# x3, y3: 3つ目の頂点の座標
# col: 三角形の色（0-15）

# 三角形を描画（枠のみ）
pyxel.trib(x1, y1, x2, y2, x3, y3, col)
# x1, y1: 1つ目の頂点の座標
# x2, y2: 2つ目の頂点の座標
# x3, y3: 3つ目の頂点の座標
# col: 枠の色（0-15）

# テキストを描画
pyxel.text(x, y, text, col)
# x, y: テキストの左上の座標
# text: 表示するテキスト
# col: テキストの色（0-15）
//}

=== 音と音楽

//list[sound_music][音と音楽][python]{
# 効果音の定義
pyxel.sound(snd).set(note, tone, volume, effect, speed)
# snd: サウンド番号（0-63）
# note: 音階（"C0", "D0", ... "B0", "C1", ... など）
# tone: 音色（"T": 三角波, "S": 矩形波, "P": パルス波, "N": ノイズ）
# volume: 音量（"0", "1", ... "7"）
# effect: エフェクト（"N": なし, "S": スライド, "V": ビブラート, "F": フェードアウト）
# speed: 再生速度（数値が大きいほど遅い）

# 効果音の再生
pyxel.play(ch, snd)
# ch: チャンネル番号（0-3）
# snd: サウンド番号（0-63）

# 音楽の定義
pyxel.music(msc).set(tracks, patterns)
# msc: ミュージック番号（0-7）
# tracks: トラックのリスト（例: [0, 1, 2, 3]）
# patterns: 各トラックのパターンのリスト（例: [[0, 1], [2, 3], [4, 5], [6, 7]]）

# 音楽の再生
pyxel.playm(msc)
# msc: ミュージック番号（0-7）

# 音の停止
pyxel.stop()
//}

=== その他

//list[others][その他][python]{
# フレームカウンターの取得
pyxel.frame_count
# 戻り値: プログラム開始からのフレーム数

# 乱数の生成
pyxel.rndi(a, b)
# a, b: 範囲（a以上b以下の整数）
# 戻り値: a以上b以下のランダムな整数

# プログラムの終了
pyxel.quit()
//}

== キーコード一覧

Pyxelでは、キーボードの各キーに対して、キーコードが定義されています。キーコードは、`pyxel.KEY_XXX`の形式で表されます。

=== 文字キー

//table[key_codes_char][文字キー]{
キーコード	説明
-----------------
pyxel.KEY_A	Aキー
pyxel.KEY_B	Bキー
pyxel.KEY_C	Cキー
...	...
pyxel.KEY_Z	Zキー
pyxel.KEY_0	0キー
pyxel.KEY_1	1キー
...	...
pyxel.KEY_9	9キー
//}

=== 特殊キー

//table[key_codes_special][特殊キー]{
キーコード	説明
-----------------
pyxel.KEY_SPACE	スペースキー
pyxel.KEY_RETURN	Enterキー
pyxel.KEY_ESCAPE	Escキー
pyxel.KEY_BACKSPACE	Backspaceキー
pyxel.KEY_TAB	Tabキー
pyxel.KEY_LEFT	左矢印キー
pyxel.KEY_RIGHT	右矢印キー
pyxel.KEY_UP	上矢印キー
pyxel.KEY_DOWN	下矢印キー
pyxel.KEY_SHIFT	Shiftキー
pyxel.KEY_CTRL	Ctrlキー
pyxel.KEY_ALT	Altキー
//}

== 色コード一覧

Pyxelでは、16色のパレットが用意されています。色は0から15までの数値で指定します。

//table[color_codes][色コード]{
色コード	色
-----------------
0	黒
1	紺色
2	紫色
3	緑色
4	茶色
5	暗い青色
6	水色
7	白
8	赤色
9	オレンジ
10	黄色
11	黄緑色
12	青色
13	ピンク
14	灰色
15	明るい灰色
//}

== 使用例

ここでは、Pyxelの命令を使った例を紹介します。

=== 基本的な使い方

//list[basic_usage][基本的な使い方][python]{
import pyxel

# Pyxelを初期化
pyxel.init(160, 120, title="Pyxelの基本")

# 画面を更新する関数
def update():
    # ESCキーが押されたら終了
    if pyxel.btnp(pyxel.KEY_ESCAPE):
        pyxel.quit()

# 画面を描画する関数
def draw():
    # 画面を黒色（0）でクリア
    pyxel.cls(0)

    # テキストを表示
    pyxel.text(55, 41, "Hello, Pyxel!", 7)

    # 四角形を描画
    pyxel.rect(50, 50, 30, 20, 11)

    # 円を描画
    pyxel.circ(80, 80, 15, 8)

# Pyxelの実行
pyxel.run(update, draw)
//}

=== キー入力の使い方

//list[key_input_usage][キー入力の使い方][python]{
import pyxel

# Pyxelを初期化
pyxel.init(160, 120, title="キー入力")

# プレイヤーの位置
player_x = 80
player_y = 60

# 画面を更新する関数
def update():
    global player_x, player_y

    # ESCキーが押されたら終了
    if pyxel.btnp(pyxel.KEY_ESCAPE):
        pyxel.quit()

    # 矢印キーでプレイヤーを移動
    if pyxel.btn(pyxel.KEY_LEFT):
        player_x = max(player_x - 2, 0)

    if pyxel.btn(pyxel.KEY_RIGHT):
        player_x = min(player_x + 2, 160 - 8)

    if pyxel.btn(pyxel.KEY_UP):
        player_y = max(player_y - 2, 0)

    if pyxel.btn(pyxel.KEY_DOWN):
        player_y = min(player_y + 2, 120 - 8)

    # スペースキーが押された瞬間に効果音を再生
    if pyxel.btnp(pyxel.KEY_SPACE):
        pyxel.play(0, 0)

# 画面を描画する関数
def draw():
    # 画面を黒色（0）でクリア
    pyxel.cls(0)

    # プレイヤーを描画
    pyxel.rect(player_x, player_y, 8, 8, 11)

    # 操作方法を表示
    pyxel.text(5, 5, "Arrow keys: Move", 7)
    pyxel.text(5, 15, "Space: Sound", 7)

# 効果音の定義
pyxel.sound(0).set(note="C4 E4 G4", tone="T", volume="7", effect="N", speed=5)

# Pyxelの実行
pyxel.run(update, draw)
//}

=== 当たり判定の使い方

//list[collision_usage][当たり判定の使い方][python]{
import pyxel
import random

# Pyxelを初期化
pyxel.init(160, 120, title="当たり判定")

# プレイヤーの位置
player_x = 80
player_y = 60

# アイテムの位置
item_x = random.randint(10, 150)
item_y = random.randint(10, 110)

# スコア
score = 0

# 画面を更新する関数
def update():
    global player_x, player_y, item_x, item_y, score

    # ESCキーが押されたら終了
    if pyxel.btnp(pyxel.KEY_ESCAPE):
        pyxel.quit()

    # 矢印キーでプレイヤーを移動
    if pyxel.btn(pyxel.KEY_LEFT):
        player_x = max(player_x - 2, 0)

    if pyxel.btn(pyxel.KEY_RIGHT):
        player_x = min(player_x + 2, 160 - 8)

    if pyxel.btn(pyxel.KEY_UP):
        player_y = max(player_y - 2, 0)

    if pyxel.btn(pyxel.KEY_DOWN):
        player_y = min(player_y + 2, 120 - 8)

    # プレイヤーとアイテムの当たり判定
    if (player_x < item_x + 8 and
        player_x + 8 > item_x and
        player_y < item_y + 8 and
        player_y + 8 > item_y):
        # アイテムを取得
        item_x = random.randint(10, 150)
        item_y = random.randint(10, 110)
        score += 1
        pyxel.play(0, 0)

# 画面を描画する関数
def draw():
    # 画面を黒色（0）でクリア
    pyxel.cls(0)

    # プレイヤーを描画
    pyxel.rect(player_x, player_y, 8, 8, 11)

    # アイテムを描画
    pyxel.rect(item_x, item_y, 8, 8, 10)

    # スコアを表示
    pyxel.text(5, 5, f"Score: {score}", 7)

# 効果音の定義
pyxel.sound(0).set(note="C4 E4 G4", tone="T", volume="7", effect="N", speed=5)

# Pyxelの実行
pyxel.run(update, draw)
//}

== まとめ

この章では、Pyxelで使える主な命令を紹介しました。

 * 基本的な命令（初期化、実行、入力、描画、音と音楽、その他）
 * キーコード一覧
 * 色コード一覧
 * 使用例（基本的な使い方、キー入力、当たり判定）

これらの命令を組み合わせることで、さまざまなゲームを作ることができます。わからない命令があるときは、この章を参考にしてください。

また、Pyxelの公式ドキュメント（https://github.com/kitao/pyxel）には、より詳しい情報が載っています。さらに学びたい場合は、公式ドキュメントも参考にしてみてください。

== チャレンジ問題

1. 次のプログラムを実行して、どのような図形が描かれるか予想してみよう。その後、実際に実行して確認しよう。

//list[challenge1][図形描画のプログラム][python]{
import pyxel

pyxel.init(160, 120)

def update():
    if pyxel.btnp(pyxel.KEY_ESCAPE):
        pyxel.quit()

def draw():
    pyxel.cls(0)
    pyxel.rect(30, 30, 30, 30, 11)
    pyxel.rectb(90, 30, 30, 30, 8)
    pyxel.circ(45, 85, 15, 10)
    pyxel.circb(105, 85, 15, 14)
    pyxel.line(30, 30, 90, 90, 7)

pyxel.run(update, draw)
//}

2. 次のプログラムを実行して、キーボードの各キーを押したときの動作を確認しよう。

//list[challenge2][キー入力のプログラム][python]{
import pyxel

pyxel.init(160, 120)

def update():
    if pyxel.btnp(pyxel.KEY_ESCAPE):
        pyxel.quit()

def draw():
    pyxel.cls(0)

    # 各キーの状態を表示
    pyxel.text(10, 10, "Arrow keys:", 7)
    pyxel.text(30, 20, "LEFT: " + ("ON" if pyxel.btn(pyxel.KEY_LEFT) else "OFF"), 7)
    pyxel.text(30, 30, "RIGHT: " + ("ON" if pyxel.btn(pyxel.KEY_RIGHT) else "OFF"), 7)
    pyxel.text(30, 40, "UP: " + ("ON" if pyxel.btn(pyxel.KEY_UP) else "OFF"), 7)
    pyxel.text(30, 50, "DOWN: " + ("ON" if pyxel.btn(pyxel.KEY_DOWN) else "OFF"), 7)

    pyxel.text(10, 70, "Other keys:", 7)
    pyxel.text(30, 80, "SPACE: " + ("ON" if pyxel.btn(pyxel.KEY_SPACE) else "OFF"), 7)
    pyxel.text(30, 90, "Z: " + ("ON" if pyxel.btn(pyxel.KEY_Z) else "OFF"), 7)
    pyxel.text(30, 100, "X: " + ("ON" if pyxel.btn(pyxel.KEY_X) else "OFF"), 7)

pyxel.run(update, draw)
//}

3. この章で紹介した命令を使って、自分だけのミニゲームを作ってみよう。例えば、マウスでキャラクターを操作するゲームや、キーボードで音楽を演奏するプログラムなど、自由に作ってみよう。