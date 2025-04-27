= 自分だけのゲームを作ろう

//lead{
この章では、これまで学んだ知識を活かして、自分だけのオリジナルゲームを作る方法を学びます。
//}

== オリジナルゲームを作るための手順

これまでの章で、Pyxelを使ったゲーム開発の基本を学んできました。図形の描画、キャラクターの移動、音の再生、当たり判定など、ゲーム開発に必要な要素を一通り学びました。

これらの知識を活かして、自分だけのオリジナルゲームを作ってみましょう。オリジナルゲームを作るには、次のような手順で進めるとよいでしょう。

 1. ゲームのアイデアを考える
 2. ゲームの設計をする
 3. プログラムを書く
 4. テストと改良を繰り返す
 5. 完成したゲームを友だちに遊んでもらう

それぞれの手順について、詳しく見ていきましょう。

== ゲームのアイデアを考える

まずは、どんなゲームを作りたいか、アイデアを考えましょう。アイデアを考えるときのポイントは次のとおりです。

=== 好きなゲームを参考にする

自分が好きなゲームを参考にするのは、アイデアを考えるための良い方法です。例えば、次のようなゲームが考えられます。

 * アクションゲーム：キャラクターを操作して障害物を避けたり、敵を倒したりするゲーム
 * パズルゲーム：ブロックを並べたり、消したりして得点を競うゲーム
 * レースゲーム：車や乗り物を操作してコースを走るゲーム
 * 収集ゲーム：アイテムを集めて得点を競うゲーム
 * 迷路ゲーム：迷路を探索して出口を目指すゲーム

=== 簡単なルールから始める

初めてオリジナルゲームを作るときは、シンプルなルールから始めるのがおすすめです。複雑なルールは、プログラミングも難しくなります。

例えば、「画面上のアイテムをすべて集める」「制限時間内に敵を倒す」「障害物を避けてゴールを目指す」など、シンプルなルールのゲームから始めましょう。

=== 自分の好きな要素を入れる

自分が好きなキャラクターや世界観、音楽などを取り入れると、作るのが楽しくなります。例えば、好きな動物をキャラクターにしたり、好きな場所を背景にしたりしてみましょう。

== ゲームの設計をする

アイデアが決まったら、ゲームの設計をしましょう。設計とは、ゲームの詳細を決めることです。

=== ゲームの目的とルールを決める

ゲームの目的（何をすればクリアか）とルール（どうやってプレイするか）を明確にしましょう。

例えば、「制限時間内にすべてのコインを集める」というゲームなら、次のように決めます。

 * 目的：すべてのコインを集める
 * ルール：
   * 矢印キーでキャラクターを操作する
   * コインに触れるとコインが消えて得点が増える
   * 敵に触れるとライフが減る
   * ライフがなくなるか、制限時間が過ぎるとゲームオーバー

=== 画面のレイアウトを考える

ゲーム画面のレイアウトを考えましょう。スコア、ライフ、時間などの表示位置や、キャラクターや背景の配置を決めます。

紙に絵を描いたり、図を作ったりして、画面のイメージを作るとよいでしょう。

=== 必要な変数とデータ構造を考える

ゲームに必要な変数（データを記録するもの）とデータ構造（データの保存方法）を考えましょう。

例えば、「コイン集めゲーム」なら、次のような変数とデータ構造が必要です。

 * プレイヤーの位置（`player_x`、`player_y`）
 * コインのリスト（各コインの位置を記録）
 * 敵のリスト（各敵の位置と移動方向を記録）
 * スコア（`score`）
 * ライフ（`lives`）
 * 制限時間（`time_left`）
 * ゲームの状態（`game_over`）

=== 関数の役割を考える

ゲームの各部分を担当する関数（処理のまとまり）を考えましょう。

基本的には、次のような関数が必要です。

 * `init_game`：ゲームの初期化
 * `update`：ゲームの状態を更新
 * `draw`：画面を描画

さらに、必要に応じて次のような関数を追加します。

 * `move_player`：プレイヤーの移動
 * `move_enemies`：敵の移動
 * `check_collisions`：当たり判定
 * `update_time`：時間の更新
 * `draw_ui`：UI（ユーザーインターフェース）の描画

== プログラムを書く

設計ができたら、実際にプログラムを書いていきましょう。

=== 基本的な構造から始める

まずは、Pyxelの基本的な構造から始めましょう。

//list[basic_structure][基本的な構造][python]{
import pyxel

# Pyxelを初期化
pyxel.init(160, 120, title="オリジナルゲーム")

# ゲームの初期化
def init_game():
    global player_x, player_y, score, lives, game_over

    # プレイヤーの位置
    player_x = 80
    player_y = 60

    # ゲームの状態
    score = 0
    lives = 3
    game_over = False

# ゲームの初期化を実行
init_game()

# 画面を更新する関数
def update():
    global player_x, player_y, score, lives, game_over

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
        player_x = max(player_x - 2, 0)

    if pyxel.btn(pyxel.KEY_RIGHT):
        player_x = min(player_x + 2, 160 - 8)

    if pyxel.btn(pyxel.KEY_UP):
        player_y = max(player_y - 2, 0)

    if pyxel.btn(pyxel.KEY_DOWN):
        player_y = min(player_y + 2, 120 - 8)

# 画面を描画する関数
def draw():
    # 画面を黒色（0）でクリア
    pyxel.cls(0)

    # プレイヤーを描画
    pyxel.rect(player_x, player_y, 8, 8, 11)

    # スコアとライフを表示
    pyxel.text(5, 5, f"Score: {score}", 7)
    pyxel.text(5, 15, f"Lives: {lives}", 7)

    # ゲームオーバー時のメッセージ
    if game_over:
        pyxel.text(55, 50, "GAME OVER", 8)
        pyxel.text(35, 70, "Press SPACE to restart", 7)

# Pyxelの実行
pyxel.run(update, draw)
//}

この基本的な構造に、自分のゲームに必要な要素を追加していきましょう。

=== 少しずつ機能を追加する

一度にすべての機能を実装しようとせず、少しずつ機能を追加していきましょう。例えば、次のような順序で実装するとよいでしょう。

 1. プレイヤーの移動
 2. 背景の描画
 3. アイテムや敵の追加
 4. 当たり判定
 5. スコアや時間の管理
 6. ゲームオーバーの処理
 7. 効果音の追加

各機能を追加するたびに、プログラムを実行してテストしましょう。

== テストと改良を繰り返す

プログラムを書いたら、実際に動かしてテストしましょう。テストでは、次のようなことをチェックします。

 * ゲームが正しく動作するか
 * バグ（プログラムの不具合）がないか
 * ゲームが面白いか
 * 難易度は適切か

テストで見つかった問題点を修正し、改良を加えていきましょう。例えば、次のような改良が考えられます。

 * 難易度の調整（敵の速度、アイテムの数など）
 * 視覚効果の追加（パーティクル、アニメーションなど）
 * 音響効果の追加（BGM、効果音など）
 * ゲームモードの追加（難易度選択、2人プレイなど）

== オリジナルゲームの例

ここでは、オリジナルゲームの例として、「宝石集めゲーム」を紹介します。このゲームは、制限時間内にできるだけ多くの宝石を集めるゲームです。

//list[jewel_game][宝石集めゲーム][python]{
import pyxel
import random

# Pyxelを初期化
pyxel.init(160, 120, title="宝石集めゲーム")

# ゲームの初期化
def init_game():
    global player_x, player_y, jewels, enemies, score, lives, time_left, game_over

    # プレイヤーの位置
    player_x = 80
    player_y = 60

    # 宝石のリスト（各宝石は[x座標, y座標, 色]のリスト）
    jewels = []
    for _ in range(10):
        jewels.append([random.randint(10, 150), random.randint(10, 110), random.randint(8, 15)])

    # 敵のリスト（各敵は[x座標, y座標, 速度X, 速度Y]のリスト）
    enemies = []
    for _ in range(5):
        enemies.append([
            random.randint(10, 150),
            random.randint(10, 110),
            random.choice([-1, 1]) * random.uniform(0.5, 1.5),
            random.choice([-1, 1]) * random.uniform(0.5, 1.5)
        ])

    # ゲームの状態
    score = 0
    lives = 3
    time_left = 30 * 30  # 30秒（30フレーム/秒）
    game_over = False

# ゲームの初期化を実行
init_game()

# 効果音の定義
# 宝石を取得した音
pyxel.sound(0).set(note="C4 E4 G4", tone="T", volume="7", effect="N", speed=5)
# ダメージを受けた音
pyxel.sound(1).set(note="C3", tone="S", volume="4", effect="N", speed=10)
# ゲームオーバー音
pyxel.sound(2).set(note="C3 C2", tone="S", volume="6", effect="F", speed=10)

# 画面を更新する関数
def update():
    global player_x, player_y, jewels, enemies, score, lives, time_left, game_over

    # ESCキーが押されたら終了
    if pyxel.btnp(pyxel.KEY_ESCAPE):
        pyxel.quit()

    # ゲームオーバー時の処理
    if game_over:
        # スペースキーでリスタート
        if pyxel.btnp(pyxel.KEY_SPACE):
            init_game()
        return

    # 時間の更新
    time_left -= 1
    if time_left <= 0:
        game_over = True
        pyxel.play(2, 2)  # ゲームオーバー音を再生
        return

    # プレイヤーの移動
    if pyxel.btn(pyxel.KEY_LEFT):
        player_x = max(player_x - 2, 0)

    if pyxel.btn(pyxel.KEY_RIGHT):
        player_x = min(player_x + 2, 160 - 8)

    if pyxel.btn(pyxel.KEY_UP):
        player_y = max(player_y - 2, 0)

    if pyxel.btn(pyxel.KEY_DOWN):
        player_y = min(player_y + 2, 120 - 8)

    # 敵の移動
    for i in range(len(enemies)):
        enemies[i][0] += enemies[i][2]
        enemies[i][1] += enemies[i][3]

        # 画面の端での反射
        if enemies[i][0] < 0 or enemies[i][0] > 160 - 8:
            enemies[i][2] = -enemies[i][2]

        if enemies[i][1] < 0 or enemies[i][1] > 120 - 8:
            enemies[i][3] = -enemies[i][3]

    # 宝石との当たり判定
    for i in range(len(jewels) - 1, -1, -1):
        if (player_x < jewels[i][0] + 6 and
            player_x + 8 > jewels[i][0] and
            player_y < jewels[i][1] + 6 and
            player_y + 8 > jewels[i][1]):
            # 宝石を取得
            jewels.pop(i)
            score += 1
            pyxel.play(0, 0)  # 宝石取得音を再生

            # すべての宝石を集めたら、新しい宝石を追加
            if len(jewels) == 0:
                for _ in range(10):
                    jewels.append([random.randint(10, 150), random.randint(10, 110), random.randint(8, 15)])

    # 敵との当たり判定
    for enemy in enemies:
        if (player_x < enemy[0] + 8 and
            player_x + 8 > enemy[0] and
            player_y < enemy[1] + 8 and
            player_y + 8 > enemy[1]):
            # ダメージを受ける
            lives -= 1
            pyxel.play(1, 1)  # ダメージ音を再生

            # プレイヤーを初期位置に戻す
            player_x = 80
            player_y = 60

            # ライフがなくなったらゲームオーバー
            if lives <= 0:
                game_over = True
                pyxel.play(2, 2)  # ゲームオーバー音を再生

            break

# 画面を描画する関数
def draw():
    # 画面を暗い青色（1）でクリア
    pyxel.cls(1)

    # 背景に星を描く
    for i in range(16):
        pyxel.pset(i * 10, 20, 7)
        pyxel.pset(i * 10 + 5, 40, 7)
        pyxel.pset(i * 10, 60, 7)
        pyxel.pset(i * 10 + 5, 80, 7)
        pyxel.pset(i * 10, 100, 7)

    # 宝石を描画
    for jewel_x, jewel_y, jewel_color in jewels:
        pyxel.rect(jewel_x, jewel_y, 6, 6, jewel_color)
        pyxel.pset(jewel_x + 2, jewel_y + 2, 7)  # 光る部分

    # 敵を描画
    for enemy_x, enemy_y, _, _ in enemies:
        pyxel.rect(enemy_x, enemy_y, 8, 8, 8)  # 赤色(8)の四角形

    # プレイヤーを描画
    pyxel.rect(player_x, player_y, 8, 8, 11)  # 黄緑色(11)の四角形

    # スコア、ライフ、時間を表示
    pyxel.text(5, 5, f"Score: {score}", 7)
    pyxel.text(5, 15, f"Lives: {lives}", 7)
    pyxel.text(5, 25, f"Time: {time_left // 30}", 7)

    # ゲームオーバー時のメッセージ
    if game_over:
        pyxel.text(55, 50, "GAME OVER", 8)
        pyxel.text(45, 70, f"Final Score: {score}", 7)
        pyxel.text(35, 90, "Press SPACE to restart", 7)

# Pyxelの実行
pyxel.run(update, draw)
//}

このゲームでは、プレイヤーが宝石を集めながら、敵を避けるというシンプルなルールになっています。制限時間内にできるだけ多くの宝石を集めることが目標です。

== 完成したゲームを友だちに遊んでもらう

オリジナルゲームが完成したら、友だちや家族に遊んでもらいましょう。他の人に遊んでもらうことで、次のようなことがわかります。

 * ゲームのルールはわかりやすいか
 * 操作は簡単か
 * 難易度は適切か
 * バグはないか
 * 面白いと感じてもらえるか

友だちからのフィードバック（感想や意見）を参考に、さらにゲームを改良していきましょう。

== まとめ

この章では、オリジナルゲームを作るための手順を学びました。

 * ゲームのアイデアを考える
 * ゲームの設計をする
 * プログラムを書く
 * テストと改良を繰り返す
 * 完成したゲームを友だちに遊んでもらう

これまでの章で学んだ知識を活かして、自分だけのオリジナルゲームを作ってみましょう。プログラミングの楽しさは、自分のアイデアを形にできることです。

次の章では、よくあるエラーと解決方法について学びます。

== チャレンジ問題

1. 「宝石集めゲーム」に新しい要素を追加してみよう。例えば、特別な宝石（得点が高い）、パワーアップアイテム（一時的に無敵になる）、ワープゾーン（別の場所に移動する）などを追加してみよう。

2. 自分の好きなキャラクターや世界観を取り入れたオリジナルゲームを考えてみよう。どんなゲームにしたいか、紙に絵を描いたり、文章にまとめたりしてみよう。

3. 友だちと一緒にゲームのアイデアを出し合って、協力してゲームを作ってみよう。一人が描画を担当し、もう一人がプログラミングを担当するなど、役割分担をしてみよう。

4. これまでの章で作ったゲーム（ボールキャッチゲーム、シューティングゲーム）をベースに、新しいルールやキャラクターを追加して、オリジナルゲームにアレンジしてみよう。

5. 自分だけのオリジナルゲームを作って、友だちや家族に遊んでもらおう。感想や意見をもらって、さらに改良してみよう。