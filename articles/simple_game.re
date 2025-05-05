= 簡単なゲームを作ろう

//lead{
この章では、これまで学んだ知識を使って、ボールキャッチゲームを作ります。
//}

== ゲームの概要

今回作るゲームは、「ボールキャッチゲーム」です。画面の上から落ちてくるボールを、プレイヤーが操作するバスケットでキャッチするゲームです。

ゲームのルールは次のとおりです。

 * プレイヤーは左右の矢印キーでバスケットを動かします。
 * 上から落ちてくるボールをバスケットでキャッチすると、得点が増えます。
 * ボールを取り逃すと、ゲームオーバーになります。
 * 得点が高いほど、ボールの落下速度が速くなります。

== ゲームの設計

ゲームを作る前に、どのような要素が必要か考えましょう。

 1. プレイヤー（バスケット）
    * 位置
    * 移動方法
    * 描画方法
 2. ボール
    * 位置
    * 落下速度
    * 描画方法
 3. ゲームの状態
    * スコア
    * ゲームオーバーフラグ
 4. 当たり判定
    * バスケットとボールの衝突判定
 5. 効果音
    * ボールをキャッチしたときの音
    * ゲームオーバーになったときの音

これらの要素を順番に実装していきましょう。

== 基本的なプログラム構造

まずは、ゲームの基本的なプログラム構造を作ります。

//list[basic_structure][基本的なプログラム構造][python]{
import pyxel
import random

# Pyxelを初期化
pyxel.init(160, 120, title="ボールキャッチゲーム")

# ゲームの初期化
def init_game():
    global player_x, ball_x, ball_y, ball_speed, score, game_over

    # プレイヤー（バスケット）の位置
    player_x = 80

    # ボールの位置と速度
    ball_x = random.randint(10, 150)
    ball_y = 0
    ball_speed = 2

    # ゲームの状態
    score = 0
    game_over = False

# ゲームの初期化を実行
init_game()

# 効果音の定義
# キャッチ音
pyxel.sound(0).set(note="C4 E4 G4", tone="T", volume="7", effect="N", speed=5)
# ゲームオーバー音
pyxel.sound(1).set(note="C3 C2", tone="S", volume="7", effect="F", speed=10)

# 画面を更新する関数
def update():
    global player_x, ball_x, ball_y, ball_speed, score, game_over

    # ESCキーが押されたら終了
    if pyxel.btnp(pyxel.KEY_ESCAPE):
        pyxel.quit()

    # ゲームオーバー時の処理
    if game_over:
        # スペースキーでリスタート
        if pyxel.btnp(pyxel.KEY_SPACE):
            init_game()
        return

    # プレイヤーの移動
    if pyxel.btn(pyxel.KEY_LEFT):
        player_x = max(player_x - 4, 20)

    if pyxel.btn(pyxel.KEY_RIGHT):
        player_x = min(player_x + 4, 140)

    # ボールの落下
    ball_y += ball_speed

    # ボールがバスケットに入ったかチェック
    if ball_y > 100 and ball_y < 110:
        if abs(ball_x - player_x) < 20:
            # ボールをキャッチした
            score += 1
            ball_x = random.randint(10, 150)
            ball_y = 0
            ball_speed = min(2 + score * 0.1, 6)  # スコアに応じて速度アップ（最大6）
            pyxel.play(0, 0)  # キャッチ音を再生

    # ボールが画面外に出たらゲームオーバー
    if ball_y > 120:
        game_over = True
        pyxel.play(1, 1)  # ゲームオーバー音を再生

# 画面を描画する関数
def draw():
    # 画面を青色（12）でクリア
    pyxel.cls(12)

    # スコアを表示
    pyxel.text(5, 5, f"Score: {score}", 7)

    # プレイヤー（バスケット）を描画
    pyxel.rect(player_x - 20, 100, 40, 10, 14)  # 灰色(14)の四角形
    pyxel.rectb(player_x - 20, 100, 40, 10, 0)  # 黒色(0)の枠

    # ボールを描画
    pyxel.circ(ball_x, ball_y, 5, 8)  # 赤色(8)の円

    # ゲームオーバー時のメッセージ
    if game_over:
        pyxel.text(55, 50, "GAME OVER", 8)
        pyxel.text(35, 70, "Press SPACE to restart", 7)

# Pyxelの実行
pyxel.run(update, draw)
//}

このプログラムをファイル名「ball_catch.py」として保存し、実行してみましょう。左右の矢印キーでバスケットを動かし、落ちてくるボールをキャッチします。ボールを取り逃すとゲームオーバーになり、スペースキーでリスタートできます。

//image[ball_catch_game][ボールキャッチゲームの実行画面]{
//}

== プログラムの解説

ボールキャッチゲームのプログラムを詳しく見ていきましょう。

=== ライブラリのインポート

//list[import_libraries][ライブラリのインポート][python]{
import pyxel
import random
//}

Pyxelに加えて、`random`ライブラリをインポートしています。これは、ボールの初期位置をランダムに設定するために使います。

=== ゲームの初期化

//list[init_game][ゲームの初期化][python]{
# ゲームの初期化
def init_game():
    global player_x, ball_x, ball_y, ball_speed, score, game_over

    # プレイヤー（バスケット）の位置
    player_x = 80

    # ボールの位置と速度
    ball_x = random.randint(10, 150)
    ball_y = 0
    ball_speed = 2

    # ゲームの状態
    score = 0
    game_over = False

# ゲームの初期化を実行
init_game()
//}

`init_game`関数では、ゲームの状態を初期化しています。

 * `player_x`：プレイヤー（バスケット）のX座標
 * `ball_x`、`ball_y`：ボールの座標
 * `ball_speed`：ボールの落下速度
 * `score`：スコア
 * `game_over`：ゲームオーバーフラグ

`random.randint(10, 150)`は、10から150までのランダムな整数を返します。これにより、ボールの初期X座標がランダムに設定されます。

=== 効果音の定義

//list[define_sounds][効果音の定義][python]{
# 効果音の定義
# キャッチ音
pyxel.sound(0).set(note="C4 E4 G4", tone="T", volume="7", effect="N", speed=5)
# ゲームオーバー音
pyxel.sound(1).set(note="C3 C2", tone="S", volume="7", effect="F", speed=10)
//}

2つの効果音を定義しています。

 * サウンド0：ボールをキャッチしたときの音（明るい上昇音）
 * サウンド1：ゲームオーバーになったときの音（暗い下降音）

=== update関数

`update`関数では、ゲームの状態を更新します。

==== ゲームオーバー時の処理

//list[game_over_handling][ゲームオーバー時の処理][python]{
# ゲームオーバー時の処理
if game_over:
    # スペースキーでリスタート
    if pyxel.btnp(pyxel.KEY_SPACE):
        init_game()
    return
//}

ゲームオーバー状態の場合、スペースキーが押されたらゲームを初期化します。`return`文により、以降の処理はスキップされます。

==== プレイヤーの移動

//list[player_movement][プレイヤーの移動][python]{
# プレイヤーの移動
if pyxel.btn(pyxel.KEY_LEFT):
    player_x = max(player_x - 4, 20)

if pyxel.btn(pyxel.KEY_RIGHT):
    player_x = min(player_x + 4, 140)
//}

左右の矢印キーでプレイヤー（バスケット）を移動します。`max`と`min`関数を使って、画面の端を超えないようにしています。

==== ボールの落下と当たり判定

//list[ball_movement_collision][ボールの落下と当たり判定][python]{
# ボールの落下
ball_y += ball_speed

# ボールがバスケットに入ったかチェック
if ball_y > 100 and ball_y < 110:
    if abs(ball_x - player_x) < 20:
        # ボールをキャッチした
        score += 1
        ball_x = random.randint(10, 150)
        ball_y = 0
        ball_speed = min(2 + score * 0.1, 6)  # スコアに応じて速度アップ（最大6）
        pyxel.play(0, 0)  # キャッチ音を再生

# ボールが画面外に出たらゲームオーバー
if ball_y > 120:
    game_over = True
    pyxel.play(1, 1)  # ゲームオーバー音を再生
//}

ボールは`ball_speed`の速度で下に落ちていきます。ボールがバスケットの高さ（Y座標が100〜110）にあり、かつX座標がバスケットの範囲内（プレイヤーのX座標から±20）にある場合、ボールをキャッチしたと判定します。

キャッチした場合は、スコアを増やし、ボールを画面上部にリセットします。また、スコアに応じてボールの速度を上げます（ただし最大6まで）。

ボールが画面下端（Y座標が120）を超えた場合、ゲームオーバーになります。

=== draw関数

`draw`関数では、ゲームの状態を画面に描画します。

//list[draw_function][draw関数][python]{
# 画面を描画する関数
def draw():
    # 画面を青色（12）でクリア
    pyxel.cls(12)

    # スコアを表示
    pyxel.text(5, 5, f"Score: {score}", 7)

    # プレイヤー（バスケット）を描画
    pyxel.rect(player_x - 20, 100, 40, 10, 14)  # 灰色(14)の四角形
    pyxel.rectb(player_x - 20, 100, 40, 10, 0)  # 黒色(0)の枠

    # ボールを描画
    pyxel.circ(ball_x, ball_y, 5, 8)  # 赤色(8)の円

    # ゲームオーバー時のメッセージ
    if game_over:
        pyxel.text(55, 50, "GAME OVER", 8)
        pyxel.text(35, 70, "Press SPACE to restart", 7)
//}

画面を青色（12）でクリアした後、スコア、プレイヤー（バスケット）、ボールを描画します。ゲームオーバー時には、「GAME OVER」と「Press SPACE to restart」というメッセージを表示します。

== ゲームの改良

基本的なボールキャッチゲームができたら、さらに改良してみましょう。

=== 複数のボール

1つのボールだけでなく、複数のボールを同時に落とすようにしてみましょう。

//list[multiple_balls][複数のボール][python]{
# ゲームの初期化
def init_game():
    global player_x, balls, score, game_over

    # プレイヤー（バスケット）の位置
    player_x = 80

    # ボールのリスト（各ボールは[x座標, y座標, 速度]のリスト）
    balls = []
    add_ball()

    # ゲームの状態
    score = 0
    game_over = False

# 新しいボールを追加
def add_ball():
    global balls
    balls.append([random.randint(10, 150), 0, random.uniform(1, 3)])

# 画面を更新する関数
def update():
    global player_x, balls, score, game_over

    # ESCキーが押されたら終了
    if pyxel.btnp(pyxel.KEY_ESCAPE):
        pyxel.quit()

    # ゲームオーバー時の処理
    if game_over:
        # スペースキーでリスタート
        if pyxel.btnp(pyxel.KEY_SPACE):
            init_game()
        return

    # プレイヤーの移動
    if pyxel.btn(pyxel.KEY_LEFT):
        player_x = max(player_x - 4, 20)

    if pyxel.btn(pyxel.KEY_RIGHT):
        player_x = min(player_x + 4, 140)

    # ボールの処理
    for i in range(len(balls) - 1, -1, -1):
        ball_x, ball_y, ball_speed = balls[i]

        # ボールの落下
        ball_y += ball_speed
        balls[i][1] = ball_y

        # ボールがバスケットに入ったかチェック
        if ball_y > 100 and ball_y < 110:
            if abs(ball_x - player_x) < 20:
                # ボールをキャッチした
                score += 1
                balls.pop(i)  # ボールを削除
                add_ball()  # 新しいボールを追加

                # スコアが5の倍数になったら、ボールを追加
                if score % 5 == 0:
                    add_ball()

                pyxel.play(0, 0)  # キャッチ音を再生

        # ボールが画面外に出たらゲームオーバー
        elif ball_y > 120:
            game_over = True
            pyxel.play(1, 1)  # ゲームオーバー音を再生

# 画面を描画する関数
def draw():
    # 画面を青色（12）でクリア
    pyxel.cls(12)

    # スコアを表示
    pyxel.text(5, 5, f"Score: {score}", 7)

    # プレイヤー（バスケット）を描画
    pyxel.rect(player_x - 20, 100, 40, 10, 14)  # 灰色(14)の四角形
    pyxel.rectb(player_x - 20, 100, 40, 10, 0)  # 黒色(0)の枠

    # ボールを描画
    for ball_x, ball_y, _ in balls:
        pyxel.circ(ball_x, ball_y, 5, 8)  # 赤色(8)の円

    # ゲームオーバー時のメッセージ
    if game_over:
        pyxel.text(55, 50, "GAME OVER", 8)
        pyxel.text(35, 70, "Press SPACE to restart", 7)
//}

このプログラムでは、ボールを`balls`というリストで管理しています。各ボールは`[x座標, y座標, 速度]`というリストで表現されています。スコアが5の倍数になるたびに、新しいボールが追加されます。

=== ライフシステム

1回ミスしただけでゲームオーバーになるのは厳しいので、ライフシステムを導入してみましょう。

//list[life_system][ライフシステム][python]{
# ゲームの初期化
def init_game():
    global player_x, ball_x, ball_y, ball_speed, score, lives, game_over

    # プレイヤー（バスケット）の位置
    player_x = 80

    # ボールの位置と速度
    ball_x = random.randint(10, 150)
    ball_y = 0
    ball_speed = 2

    # ゲームの状態
    score = 0
    lives = 3  # ライフ数
    game_over = False

# 画面を更新する関数
def update():
    global player_x, ball_x, ball_y, ball_speed, score, lives, game_over

    # ESCキーが押されたら終了
    if pyxel.btnp(pyxel.KEY_ESCAPE):
        pyxel.quit()

    # ゲームオーバー時の処理
    if game_over:
        # スペースキーでリスタート
        if pyxel.btnp(pyxel.KEY_SPACE):
            init_game()
        return

    # プレイヤーの移動
    if pyxel.btn(pyxel.KEY_LEFT):
        player_x = max(player_x - 4, 20)

    if pyxel.btn(pyxel.KEY_RIGHT):
        player_x = min(player_x + 4, 140)

    # ボールの落下
    ball_y += ball_speed

    # ボールがバスケットに入ったかチェック
    if ball_y > 100 and ball_y < 110:
        if abs(ball_x - player_x) < 20:
            # ボールをキャッチした
            score += 1
            ball_x = random.randint(10, 150)
            ball_y = 0
            ball_speed = min(2 + score * 0.1, 6)  # スコアに応じて速度アップ（最大6）
            pyxel.play(0, 0)  # キャッチ音を再生

    # ボールが画面外に出たらライフを減らす
    if ball_y > 120:
        lives -= 1
        ball_x = random.randint(10, 150)
        ball_y = 0
        pyxel.play(1, 1)  # ミス音を再生

        # ライフがなくなったらゲームオーバー
        if lives <= 0:
            game_over = True

# 画面を描画する関数
def draw():
    # 画面を青色（12）でクリア
    pyxel.cls(12)

    # スコアとライフを表示
    pyxel.text(5, 5, f"Score: {score}", 7)
    pyxel.text(5, 15, f"Lives: {lives}", 7)

    # プレイヤー（バスケット）を描画
    pyxel.rect(player_x - 20, 100, 40, 10, 14)  # 灰色(14)の四角形
    pyxel.rectb(player_x - 20, 100, 40, 10, 0)  # 黒色(0)の枠

    # ボールを描画
    pyxel.circ(ball_x, ball_y, 5, 8)  # 赤色(8)の円

    # ゲームオーバー時のメッセージ
    if game_over:
        pyxel.text(55, 50, "GAME OVER", 8)
        pyxel.text(35, 70, "Press SPACE to restart", 7)
//}

このプログラムでは、プレイヤーに3つのライフが与えられます。ボールを取り逃すとライフが1つ減り、ライフがなくなるとゲームオーバーになります。

=== ハイスコア

プレイヤーのモチベーションを高めるために、ハイスコアを記録してみましょう。

//list[high_score][ハイスコア][python]{
# ゲームの初期化
def init_game():
    global player_x, ball_x, ball_y, ball_speed, score, high_score, game_over

    # プレイヤー（バスケット）の位置
    player_x = 80

    # ボールの位置と速度
    ball_x = random.randint(10, 150)
    ball_y = 0
    ball_speed = 2

    # ゲームの状態
    score = 0
    game_over = False

# ハイスコアの初期化
high_score = 0

# 画面を更新する関数
def update():
    global player_x, ball_x, ball_y, ball_speed, score, high_score, game_over

    # ESCキーが押されたら終了
    if pyxel.btnp(pyxel.KEY_ESCAPE):
        pyxel.quit()

    # ゲームオーバー時の処理
    if game_over:
        # ハイスコアの更新
        if score > high_score:
            high_score = score

        # スペースキーでリスタート
        if pyxel.btnp(pyxel.KEY_SPACE):
            init_game()
        return

    # プレイヤーの移動と当たり判定の処理...

# 画面を描画する関数
def draw():
    # 画面を青色（12）でクリア
    pyxel.cls(12)

    # スコアとハイスコアを表示
    pyxel.text(5, 5, f"Score: {score}", 7)
    pyxel.text(5, 15, f"High Score: {high_score}", 7)

    # プレイヤー、ボール、ゲームオーバーメッセージの描画...
//}

このプログラムでは、ゲームオーバー時にスコアがハイスコアを超えていれば、ハイスコアを更新します。

== まとめ

この章では、これまで学んだ知識を使って、ボールキャッチゲームを作りました。

 * ゲームの基本構造（初期化、更新、描画）
 * プレイヤーの移動と入力の処理
 * ボールの落下と当たり判定
 * スコアとゲームオーバーの処理
 * 効果音の追加
 * ゲームの改良（複数のボール、ライフシステム、ハイスコア）

これらの要素は、多くのゲームに共通する基本的な要素です。この知識を応用すれば、さまざまなゲームを作ることができます。

次の章では、もう少し複雑なシューティングゲームを作ります。

== チャレンジ問題

1. ボールの色をランダムに変えてみよう。色によって得点が変わるようにしてみよう。

2. ボールの大きさをランダムに変えてみよう。大きいボールは取りやすいが得点が低く、小さいボールは取りにくいが得点が高いようにしてみよう。

3. タイマーを追加して、制限時間内にどれだけ得点を稼げるかを競うゲームにしてみよう。

4. バスケットの大きさをスコアに応じて小さくしていくようにして、難易度を上げてみよう。

5. 自分だけのアイデアを加えて、オリジナルのボールキャッチゲームを作ってみよう。