= キャラクターを動かそう

//lead{
この章では、キーボードの入力を受け付けて、キャラクターを画面上で動かす方法を学びます。
//}

== キャラクターの動きの基本

ゲームでは、プレイヤーがキーボードやマウスを操作して、キャラクターを動かすことが基本です。Pyxelでは、キーボードの入力を簡単に受け付けることができます。

キャラクターを動かすには、次の手順が必要です。

 1. キャラクターの位置を記録する変数を用意する
 2. キーボードの入力を受け付ける
 3. 入力に応じてキャラクターの位置を更新する
 4. 新しい位置にキャラクターを描画する

それでは、順番に見ていきましょう。

== 基本的なプログラム構造

まずは、キャラクターを動かすための基本的なプログラム構造を確認しましょう。

//list[basic_structure][基本的なプログラム構造][python]{
import pyxel

# Pyxelを初期化
pyxel.init(160, 120, title="キャラクターを動かそう")

# キャラクターの位置
player_x = 80  # 初期X座標
player_y = 60  # 初期Y座標

# 画面を更新する関数
def update():
    global player_x, player_y

    # ESCキーが押されたら終了
    if pyxel.btnp(pyxel.KEY_ESCAPE):
        pyxel.quit()

    # ここにキャラクターを動かすコードを書きます

# 画面を描画する関数
def draw():
    # 画面を黒色（0）でクリア
    pyxel.cls(0)

    # キャラクターを描画
    pyxel.circ(player_x, player_y, 10, 7)  # 白色(7)の円をキャラクターとして描画

# Pyxelの実行
pyxel.run(update, draw)
//}

このプログラムをファイル名「character.py」として保存し、これから学ぶキャラクター移動のコードを`update`関数の中に追加していきます。

== グローバル変数

プログラムの最初に、キャラクターの位置を記録する変数（`player_x`と`player_y`）を定義しています。これらの変数は「グローバル変数」と呼ばれ、プログラム全体で使うことができます。

//list[global_variables][グローバル変数][python]{
# キャラクターの位置
player_x = 80  # 初期X座標
player_y = 60  # 初期Y座標
//}

`update`関数の中でこれらの変数を変更するには、`global`キーワードを使って、これらの変数がグローバル変数であることを宣言する必要があります。

//list[global_keyword][globalキーワード][python]{
def update():
    global player_x, player_y

    # ここでplayer_xとplayer_yを変更できます
//}

== キーボード入力の受け付け

Pyxelでは、キーボードの入力を受け付けるために、`btn`関数と`btnp`関数を使います。

 * `btn`：キーが押されている間、常に`True`を返します。
 * `btnp`：キーが押された瞬間だけ`True`を返します。

今回は、キャラクターを連続して動かしたいので、`btn`関数を使います。

//list[keyboard_input][キーボード入力の受け付け][python]{
# キーボード入力の受け付け
if pyxel.btn(pyxel.KEY_LEFT):
    player_x -= 2  # 左キーが押されたら、X座標を減らす（左に移動）

if pyxel.btn(pyxel.KEY_RIGHT):
    player_x += 2  # 右キーが押されたら、X座標を増やす（右に移動）

if pyxel.btn(pyxel.KEY_UP):
    player_y -= 2  # 上キーが押されたら、Y座標を減らす（上に移動）

if pyxel.btn(pyxel.KEY_DOWN):
    player_y += 2  # 下キーが押されたら、Y座標を増やす（下に移動）
//}

このコードでは、矢印キー（←→↑↓）の入力を受け付けて、キャラクターの位置（`player_x`と`player_y`）を更新しています。

== 画面の端での処理

このままだと、キャラクターが画面の外に出てしまう可能性があります。画面の端に来たら、それ以上移動できないようにしましょう。

//list[screen_boundary][画面の端での処理][python]{
# 画面の端での処理
if player_x < 10:
    player_x = 10  # 左端
if player_x > 150:
    player_x = 150  # 右端
if player_y < 10:
    player_y = 10  # 上端
if player_y > 110:
    player_y = 110  # 下端
//}

このコードでは、キャラクターの位置が画面の端（余白を考慮）に来たら、それ以上移動できないようにしています。

== キャラクターの描画

`draw`関数では、更新されたキャラクターの位置に円を描画しています。

//list[draw_character][キャラクターの描画][python]{
# キャラクターを描画
pyxel.circ(player_x, player_y, 10, 7)  # 白色(7)の円をキャラクターとして描画
//}

ここでは簡単のために円を使っていますが、前の章で学んだ様々な図形を組み合わせて、もっと複雑なキャラクターを描くこともできます。

== 完成したプログラム

これまで学んだキャラクター移動の方法を使って、完成したプログラムを作ってみましょう。

//list[complete_program][完成したプログラム][python]{
import pyxel

# Pyxelを初期化
pyxel.init(160, 120, title="キャラクターを動かそう")

# キャラクターの位置
player_x = 80  # 初期X座標
player_y = 60  # 初期Y座標

# 画面を更新する関数
def update():
    global player_x, player_y

    # ESCキーが押されたら終了
    if pyxel.btnp(pyxel.KEY_ESCAPE):
        pyxel.quit()

    # キーボード入力の受け付け
    if pyxel.btn(pyxel.KEY_LEFT):
        player_x -= 2  # 左キーが押されたら、X座標を減らす（左に移動）

    if pyxel.btn(pyxel.KEY_RIGHT):
        player_x += 2  # 右キーが押されたら、X座標を増やす（右に移動）

    if pyxel.btn(pyxel.KEY_UP):
        player_y -= 2  # 上キーが押されたら、Y座標を減らす（上に移動）

    if pyxel.btn(pyxel.KEY_DOWN):
        player_y += 2  # 下キーが押されたら、Y座標を増やす（下に移動）

    # 画面の端での処理
    if player_x < 10:
        player_x = 10  # 左端
    if player_x > 150:
        player_x = 150  # 右端
    if player_y < 10:
        player_y = 10  # 上端
    if player_y > 110:
        player_y = 110  # 下端

# 画面を描画する関数
def draw():
    # 画面を黒色（0）でクリア
    pyxel.cls(0)

    # 背景に星を描く
    for i in range(16):
        pyxel.pset(i * 10, 20, 7)  # 白色(7)の点
        pyxel.pset(i * 10 + 5, 40, 7)  # 白色(7)の点
        pyxel.pset(i * 10, 60, 7)  # 白色(7)の点
        pyxel.pset(i * 10 + 5, 80, 7)  # 白色(7)の点
        pyxel.pset(i * 10, 100, 7)  # 白色(7)の点

    # キャラクターを描画（宇宙飛行士）
    # 体
    pyxel.circ(player_x, player_y, 10, 7)  # 白色(7)の円

    # 顔
    pyxel.circ(player_x, player_y - 2, 6, 6)  # 水色(6)の円

    # 目
    pyxel.pset(player_x - 2, player_y - 3, 0)  # 黒色(0)の点
    pyxel.pset(player_x + 2, player_y - 3, 0)  # 黒色(0)の点

    # 口
    pyxel.line(player_x - 2, player_y, player_x + 2, player_y, 0)  # 黒色(0)の線

    # 手足
    pyxel.line(player_x - 10, player_y, player_x - 15, player_y - 5, 7)  # 左手
    pyxel.line(player_x + 10, player_y, player_x + 15, player_y - 5, 7)  # 右手
    pyxel.line(player_x - 5, player_y + 10, player_x - 5, player_y + 15, 7)  # 左足
    pyxel.line(player_x + 5, player_y + 10, player_x + 5, player_y + 15, 7)  # 右足

    # 操作方法を表示
    pyxel.text(5, 5, "Arrow keys: Move", 7)

# Pyxelの実行
pyxel.run(update, draw)
//}

このプログラムを実行すると、矢印キーで宇宙飛行士のキャラクターを動かすことができます。

//image[complete_program_image][完成したプログラムの実行結果]{
//}

== 応用：スピードの変更

キャラクターの移動スピードを変更するには、座標の増減値を変更します。

//list[change_speed][スピードの変更][python]{
# スピードを変更（1から5の間で調整）
speed = 3

# キーボード入力の受け付け
if pyxel.btn(pyxel.KEY_LEFT):
    player_x -= speed  # 左に移動

if pyxel.btn(pyxel.KEY_RIGHT):
    player_x += speed  # 右に移動

if pyxel.btn(pyxel.KEY_UP):
    player_y -= speed  # 上に移動

if pyxel.btn(pyxel.KEY_DOWN):
    player_y += speed  # 下に移動
//}

== 応用：斜め移動

斜め移動をスムーズにするには、同時に押されたキーを考慮する必要があります。

//list[diagonal_movement][斜め移動][python]{
# 移動方向を記録する変数
dx = 0  # X方向の移動量
dy = 0  # Y方向の移動量

# キーボード入力の受け付け
if pyxel.btn(pyxel.KEY_LEFT):
    dx = -2  # 左に移動
elif pyxel.btn(pyxel.KEY_RIGHT):
    dx = 2   # 右に移動
else:
    dx = 0   # X方向には移動しない

if pyxel.btn(pyxel.KEY_UP):
    dy = -2  # 上に移動
elif pyxel.btn(pyxel.KEY_DOWN):
    dy = 2   # 下に移動
else:
    dy = 0   # Y方向には移動しない

# 位置の更新
player_x += dx
player_y += dy
//}

== 応用：アニメーション

キャラクターにアニメーションをつけるには、フレームカウンターを使います。

//list[animation][アニメーション][python]{
# フレームカウンター
frame_count = 0

def update():
    global player_x, player_y, frame_count

    # フレームカウンターを更新
    frame_count = (frame_count + 1) % 30  # 0から29までのループ

    # キャラクターの移動処理...

def draw():
    # 画面のクリア...

    # アニメーションするキャラクター
    if frame_count < 15:
        # アニメーション1コマ目
        pyxel.circ(player_x, player_y, 10, 7)
        # 足を前に出す
        pyxel.line(player_x - 5, player_y + 10, player_x - 10, player_y + 15, 7)  # 左足
        pyxel.line(player_x + 5, player_y + 10, player_x + 10, player_y + 15, 7)  # 右足
    else:
        # アニメーション2コマ目
        pyxel.circ(player_x, player_y, 10, 7)
        # 足を後ろに引く
        pyxel.line(player_x - 5, player_y + 10, player_x - 5, player_y + 15, 7)  # 左足
        pyxel.line(player_x + 5, player_y + 10, player_x + 5, player_y + 15, 7)  # 右足
//}

== まとめ

この章では、キーボード入力を受け付けて、キャラクターを画面上で動かす方法を学びました。

 * キャラクターの位置を記録する変数の使い方
 * キーボード入力の受け付け方法（`btn`関数）
 * 画面の端での処理方法
 * キャラクターの描画方法
 * 応用テクニック（スピード変更、斜め移動、アニメーション）

これらの技術を使えば、プレイヤーが操作できるキャラクターを作ることができます。次の章では、音を鳴らす方法を学びます。

== チャレンジ問題

1. キャラクターの見た目を変えてみよう。円の代わりに、四角形や三角形を使ったり、複数の図形を組み合わせたりしてみよう。

2. キャラクターの移動スピードを変更してみよう。速すぎず、遅すぎない、ちょうどいいスピードを見つけよう。

3. スペースキー（`pyxel.KEY_SPACE`）を押したときに、キャラクターの色が変わるようにしてみよう。

4. 画面上に障害物（例：四角形）を配置して、キャラクターがぶつからないように移動させるゲームを作ってみよう。