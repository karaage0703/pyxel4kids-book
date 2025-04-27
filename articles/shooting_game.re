= もっと複雑なゲームを作ろう

//lead{
この章では、前の章で学んだ知識を発展させて、シューティングゲームを作ります。
//}

== シューティングゲームの概要

今回作るゲームは、横スクロールシューティングゲームです。プレイヤーが操作する宇宙船で、次々と現れる敵を撃ち落としていくゲームです。

ゲームのルールは次のとおりです。

 * プレイヤーは上下左右の矢印キーで宇宙船を動かします。
 * スペースキーを押すと、弾を発射します。
 * 敵に弾が当たると、敵が消えて得点が増えます。
 * 敵と宇宙船が衝突すると、ライフが減ります。
 * ライフがなくなると、ゲームオーバーになります。

== ゲームの設計

シューティングゲームを作るために、次のような要素が必要です。

 1. プレイヤー（宇宙船）
    * 位置
    * 移動方法
    * 描画方法
 2. 弾
    * 位置
    * 移動方法
    * 描画方法
 3. 敵
    * 位置
    * 移動方法
    * 描画方法
 4. ゲームの状態
    * スコア
    * ライフ
    * ゲームオーバーフラグ
 5. 当たり判定
    * 弾と敵の衝突判定
    * プレイヤーと敵の衝突判定
 6. 効果音
    * 弾の発射音
    * 敵を倒したときの音
    * ダメージを受けたときの音
    * ゲームオーバーになったときの音

これらの要素を順番に実装していきましょう。

== 基本的なプログラム構造

まずは、シューティングゲームの基本的なプログラム構造を作ります。

//list[basic_structure][基本的なプログラム構造][python]{
import pyxel
import random

# Pyxelを初期化
pyxel.init(160, 120, title="シューティングゲーム")

# ゲームの初期化
def init_game():
    global player_x, player_y, bullets, enemies, score, lives, game_over

    # プレイヤー（宇宙船）の位置
    player_x = 20
    player_y = 60

    # 弾のリスト（各弾は[x座標, y座標]のリスト）
    bullets = []

    # 敵のリスト（各敵は[x座標, y座標, 速度]のリスト）
    enemies = []

    # ゲームの状態
    score = 0
    lives = 3
    game_over = False

# ゲームの初期化を実行
init_game()

# 効果音の定義
# 弾の発射音
pyxel.sound(0).set(note="C5", tone="P", volume="3", effect="N", speed=5)
# 敵を倒した音
pyxel.sound(1).set(note="C4 E4 G4", tone="T", volume="5", effect="N", speed=5)
# ダメージを受けた音
pyxel.sound(2).set(note="C3", tone="S", volume="4", effect="N", speed=10)
# ゲームオーバー音
pyxel.sound(3).set(note="C3 C2", tone="S", volume="6", effect="F", speed=10)

# 画面を更新する関数
def update():
    global player_x, player_y, bullets, enemies, score, lives, game_over

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

    # 弾の発射
    if pyxel.btnp(pyxel.KEY_SPACE):
        bullets.append([player_x + 8, player_y + 4])
        pyxel.play(0, 0)  # 弾の発射音を再生

    # 弾の移動
    for i in range(len(bullets) - 1, -1, -1):
        bullets[i][0] += 4  # 弾は右に移動

        # 画面外に出た弾を削除
        if bullets[i][0] > 160:
            bullets.pop(i)

    # 敵の生成（一定確率で）
    if random.random() < 0.05:
        enemies.append([160, random.randint(0, 112), random.uniform(1, 3)])

    # 敵の移動
    for i in range(len(enemies) - 1, -1, -1):
        enemies[i][0] -= enemies[i][2]  # 敵は左に移動

        # 画面外に出た敵を削除
        if enemies[i][0] < -8:
            enemies.pop(i)

    # 当たり判定（弾と敵）
    for i in range(len(bullets) - 1, -1, -1):
        for j in range(len(enemies) - 1, -1, -1):
            if (bullets[i][0] < enemies[j][0] + 8 and
                bullets[i][0] + 2 > enemies[j][0] and
                bullets[i][1] < enemies[j][1] + 8 and
                bullets[i][1] + 2 > enemies[j][1]):
                # 弾が敵に当たった
                bullets.pop(i)
                enemies.pop(j)
                score += 1
                pyxel.play(1, 1)  # 敵を倒した音を再生
                break

    # 当たり判定（プレイヤーと敵）
    for i in range(len(enemies) - 1, -1, -1):
        if (player_x < enemies[i][0] + 8 and
            player_x + 8 > enemies[i][0] and
            player_y < enemies[i][1] + 8 and
            player_y + 8 > enemies[i][1]):
            # プレイヤーが敵に当たった
            enemies.pop(i)
            lives -= 1
            pyxel.play(2, 2)  # ダメージを受けた音を再生

            # ライフがなくなったらゲームオーバー
            if lives <= 0:
                game_over = True
                pyxel.play(3, 3)  # ゲームオーバー音を再生
            break

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

    # ゲームオーバーでなければ、ゲーム要素を描画
    if not game_over:
        # プレイヤー（宇宙船）を描画
        pyxel.rect(player_x, player_y, 8, 8, 11)  # 黄緑色(11)の四角形
        pyxel.tri(player_x, player_y, player_x, player_y + 8, player_x - 4, player_y + 4, 11)  # 先端

        # 弾を描画
        for bullet_x, bullet_y in bullets:
            pyxel.rect(bullet_x, bullet_y, 2, 2, 10)  # 黄色(10)の四角形

        # 敵を描画
        for enemy_x, enemy_y, _ in enemies:
            pyxel.rect(enemy_x, enemy_y, 8, 8, 8)  # 赤色(8)の四角形

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

このプログラムをファイル名「shooting_game.py」として保存し、実行してみましょう。矢印キーで宇宙船を動かし、スペースキーで弾を発射して敵を倒します。敵と衝突するとライフが減り、ライフがなくなるとゲームオーバーになります。スペースキーでリスタートできます。

//comment{
実際のゲームを実行すると、黒い背景に宇宙船と敵が表示され、弾を撃って敵を倒すゲーム画面が表示されます。
//}
== プログラムの解説

シューティングゲームのプログラムを詳しく見ていきましょう。

=== ゲームの初期化

//list[init_game][ゲームの初期化][python]{
# ゲームの初期化
def init_game():
    global player_x, player_y, bullets, enemies, score, lives, game_over

    # プレイヤー（宇宙船）の位置
    player_x = 20
    player_y = 60

    # 弾のリスト（各弾は[x座標, y座標]のリスト）
    bullets = []

    # 敵のリスト（各敵は[x座標, y座標, 速度]のリスト）
    enemies = []

    # ゲームの状態
    score = 0
    lives = 3
    game_over = False
//}

`init_game`関数では、ゲームの状態を初期化しています。

 * `player_x`、`player_y`：プレイヤー（宇宙船）の座標
 * `bullets`：弾のリスト（各弾は`[x座標, y座標]`のリスト）
 * `enemies`：敵のリスト（各敵は`[x座標, y座標, 速度]`のリスト）
 * `score`：スコア
 * `lives`：ライフ数
 * `game_over`：ゲームオーバーフラグ

=== 効果音の定義

//list[define_sounds][効果音の定義][python]{
# 効果音の定義
# 弾の発射音
pyxel.sound(0).set(note="C5", tone="P", volume="3", effect="N", speed=5)
# 敵を倒した音
pyxel.sound(1).set(note="C4 E4 G4", tone="T", volume="5", effect="N", speed=5)
# ダメージを受けた音
pyxel.sound(2).set(note="C3", tone="S", volume="4", effect="N", speed=10)
# ゲームオーバー音
pyxel.sound(3).set(note="C3 C2", tone="S", volume="6", effect="F", speed=10)
//}

4つの効果音を定義しています。

 * サウンド0：弾の発射音（高い単音）
 * サウンド1：敵を倒した音（明るい上昇音）
 * サウンド2：ダメージを受けた音（低い単音）
 * サウンド3：ゲームオーバー音（暗い下降音）

=== update関数

`update`関数では、ゲームの状態を更新します。

==== プレイヤーの移動と弾の発射

//list[player_movement_shooting][プレイヤーの移動と弾の発射][python]{
# プレイヤーの移動
if pyxel.btn(pyxel.KEY_LEFT):
    player_x = max(player_x - 2, 0)

if pyxel.btn(pyxel.KEY_RIGHT):
    player_x = min(player_x + 2, 160 - 8)

if pyxel.btn(pyxel.KEY_UP):
    player_y = max(player_y - 2, 0)

if pyxel.btn(pyxel.KEY_DOWN):
    player_y = min(player_y + 2, 120 - 8)

# 弾の発射
if pyxel.btnp(pyxel.KEY_SPACE):
    bullets.append([player_x + 8, player_y + 4])
    pyxel.play(0, 0)  # 弾の発射音を再生
//}

上下左右の矢印キーでプレイヤー（宇宙船）を移動します。`max`と`min`関数を使って、画面の端を超えないようにしています。

スペースキーを押すと、弾を発射します。弾の初期位置は、宇宙船の先端（`player_x + 8, player_y + 4`）に設定されます。

==== 弾の移動

//list[bullet_movement][弾の移動][python]{
# 弾の移動
for i in range(len(bullets) - 1, -1, -1):
    bullets[i][0] += 4  # 弾は右に移動

    # 画面外に出た弾を削除
    if bullets[i][0] > 160:
        bullets.pop(i)
//}

弾は右に移動します（X座標が増加）。画面外に出た弾は削除します。

リストの要素を削除する際は、後ろから前に処理することで、インデックスのずれを防いでいます。

==== 敵の生成と移動

//list[enemy_generation_movement][敵の生成と移動][python]{
# 敵の生成（一定確率で）
if random.random() < 0.05:
    enemies.append([160, random.randint(0, 112), random.uniform(1, 3)])

# 敵の移動
for i in range(len(enemies) - 1, -1, -1):
    enemies[i][0] -= enemies[i][2]  # 敵は左に移動

    # 画面外に出た敵を削除
    if enemies[i][0] < -8:
        enemies.pop(i)
//}

敵は一定確率（5%）で画面右端に生成されます。Y座標はランダムに設定され、速度も1〜3の間でランダムに設定されます。

敵は左に移動します（X座標が減少）。画面外に出た敵は削除します。

==== 当たり判定

//list[collision_detection][当たり判定][python]{
# 当たり判定（弾と敵）
for i in range(len(bullets) - 1, -1, -1):
    for j in range(len(enemies) - 1, -1, -1):
        if (bullets[i][0] < enemies[j][0] + 8 and
            bullets[i][0] + 2 > enemies[j][0] and
            bullets[i][1] < enemies[j][1] + 8 and
            bullets[i][1] + 2 > enemies[j][1]):
            # 弾が敵に当たった
            bullets.pop(i)
            enemies.pop(j)
            score += 1
            pyxel.play(1, 1)  # 敵を倒した音を再生
            break

# 当たり判定（プレイヤーと敵）
for i in range(len(enemies) - 1, -1, -1):
    if (player_x < enemies[i][0] + 8 and
        player_x + 8 > enemies[i][0] and
        player_y < enemies[i][1] + 8 and
        player_y + 8 > enemies[i][1]):
        # プレイヤーが敵に当たった
        enemies.pop(i)
        lives -= 1
        pyxel.play(2, 2)  # ダメージを受けた音を再生

        # ライフがなくなったらゲームオーバー
        if lives <= 0:
            game_over = True
            pyxel.play(3, 3)  # ゲームオーバー音を再生
        break
//}

当たり判定は、2つのオブジェクトの矩形が重なっているかどうかをチェックします。

弾と敵の当たり判定では、弾が敵に当たった場合、弾と敵を削除し、スコアを増やします。

プレイヤーと敵の当たり判定では、プレイヤーが敵に当たった場合、敵を削除し、ライフを減らします。ライフがなくなると、ゲームオーバーになります。

== ゲームの改良

基本的なシューティングゲームができたら、さらに改良してみましょう。ここでは、いくつかの改良案を紹介します。

=== 敵の種類を増やす

敵の種類を増やして、ゲームをより面白くしましょう。

//list[multiple_enemy_types][敵の種類を増やす][python]{
# 敵の生成（一定確率で）
if random.random() < 0.05:
    # 敵の種類をランダムに決定（0: 通常の敵, 1: 速い敵, 2: 大きい敵）
    enemy_type = random.randint(0, 2)

    if enemy_type == 0:
        # 通常の敵
        enemies.append([160, random.randint(0, 112), random.uniform(1, 2), 8, 8, 8, 1])
    elif enemy_type == 1:
        # 速い敵
        enemies.append([160, random.randint(0, 112), random.uniform(2, 4), 6, 6, 9, 1])
    else:
        # 大きい敵
        enemies.append([160, random.randint(0, 104), random.uniform(0.5, 1), 16, 16, 14, 3])

# 敵の描画
for enemy in enemies:
    enemy_x, enemy_y, _, width, height, color, _ = enemy
    pyxel.rect(enemy_x, enemy_y, width, height, color)
//}

敵のリストの各要素を`[x座標, y座標, 速度, 幅, 高さ, 色, 耐久力]`のリストに変更しています。敵の種類によって、速度、大きさ、色、耐久力が異なります。

=== パワーアップアイテム

敵を倒すと、一定確率でパワーアップアイテムが出現するようにしましょう。

//list[power_up_items][パワーアップアイテム][python]{
# ゲームの初期化
def init_game():
    global player_x, player_y, bullets, enemies, items, score, lives, power_level, game_over

    # プレイヤー（宇宙船）の位置
    player_x = 20
    player_y = 60

    # 弾のリスト
    bullets = []

    # 敵のリスト
    enemies = []

    # アイテムのリスト（各アイテムは[x座標, y座標, 種類]のリスト）
    items = []

    # ゲームの状態
    score = 0
    lives = 3
    power_level = 0  # パワーレベル（0: 通常, 1: 2連射, 2: 3連射）
    game_over = False

# 弾の発射
if pyxel.btnp(pyxel.KEY_SPACE):
    if power_level == 0:
        # 通常の弾
        bullets.append([player_x + 8, player_y + 4])
    elif power_level == 1:
        # 2連射
        bullets.append([player_x + 8, player_y + 2])
        bullets.append([player_x + 8, player_y + 6])
    else:
        # 3連射
        bullets.append([player_x + 8, player_y])
        bullets.append([player_x + 8, player_y + 4])
        bullets.append([player_x + 8, player_y + 8])

    pyxel.play(0, 0)  # 弾の発射音を再生
//}

パワーアップアイテムを取得すると、弾の発射数が増えます（1発→2発→3発）。

=== ボス敵

一定スコアに達すると、ボス敵が出現するようにしましょう。

//list[boss_enemy][ボス敵][python]{
# ゲームの初期化
def init_game():
    global player_x, player_y, bullets, enemies, items, boss, boss_hp, score, lives, power_level, game_over, boss_mode

    # プレイヤー（宇宙船）の位置
    player_x = 20
    player_y = 60

    # 弾のリスト
    bullets = []

    # 敵のリスト
    enemies = []

    # アイテムのリスト
    items = []

    # ボス敵
    boss = None  # ボスがいない状態
    boss_hp = 0  # ボスの体力

    # ゲームの状態
    score = 0
    lives = 3
    power_level = 0
    game_over = False
    boss_mode = False  # ボスモードフラグ

# update関数内
# ボスモードの切り替え
if not boss_mode and score >= 20:  # スコアが20以上でボスモードに
    boss_mode = True
    enemies = []  # 通常の敵をクリア
    boss = [120, 60, 1]  # ボスの初期位置と移動方向（1: 下, -1: 上）
    boss_hp = 20  # ボスの体力

# ボスの移動と攻撃
if boss_mode and boss:
    # ボスの移動（上下に動く）
    boss[1] += boss[2]
    if boss[1] < 10 or boss[1] > 90:
        boss[2] = -boss[2]  # 方向転換

    # ボスの攻撃（一定確率で弾を発射）
    if random.random() < 0.1:
        enemies.append([boss[0] - 8, boss[1] + 10, 2, 8, 8, 8, 1])  # ボスから弾が出る

    # プレイヤーの弾とボスの当たり判定
    for i in range(len(bullets) - 1, -1, -1):
        if (bullets[i][0] < boss[0] + 20 and
            bullets[i][0] + 2 > boss[0] - 20 and
            bullets[i][1] < boss[1] + 20 and
            bullets[i][1] + 2 > boss[1] - 20):
            # 弾がボスに当たった
            bullets.pop(i)
            boss_hp -= 1
            pyxel.play(1, 1)  # ヒット音を再生

            # ボスを倒した
            if boss_hp <= 0:
                boss = None
                score += 30  # ボーナス得点
                pyxel.play(1, 1)  # 敵を倒した音を再生
                boss_mode = False  # ボスモード終了
            break

# ボスの描画
if boss_mode and boss:
    # ボスを描画
    pyxel.rect(boss[0] - 20, boss[1] - 20, 40, 40, 8)  # 赤色(8)の大きな四角形
    pyxel.text(boss[0] - 10, boss[1], f"HP: {boss_hp}", 7)  # 体力表示
//}

スコアが一定値（ここでは20）に達すると、ボスモードに切り替わります。ボスは大きな敵で、体力が多く、弾を発射してきます。ボスを倒すとボーナス得点が入り、通常モードに戻ります。

== まとめ

この章では、シューティングゲームを作りました。

 * プレイヤー（宇宙船）の移動と弾の発射
 * 敵の生成と移動
 * 当たり判定（弾と敵、プレイヤーと敵）
 * スコアとライフの管理
 * ゲームオーバーの処理
 * 効果音の追加
 * ゲームの改良（敵の種類、パワーアップアイテム、ボス敵）

これらの要素は、多くのシューティングゲームに共通する基本的な要素です。この知識を応用すれば、さまざまなシューティングゲームを作ることができます。

次の章では、これまで学んだ知識を活かして、自分だけのオリジナルゲームを作る方法を学びます。

== チャレンジ問題

1. 敵の動きをもっと複雑にしてみよう。例えば、ジグザグに動いたり、プレイヤーを追いかけたりする敵を作ってみよう。

2. ボスの攻撃パターンを増やしてみよう。例えば、複数の弾を一度に発射したり、レーザービームを発射したりするボスを作ってみよう。

3. ステージ制を導入してみよう。一定スコアごとに背景や敵の種類が変わるようにしてみよう。

4. 2人プレイモードを追加してみよう。2人目のプレイヤーはWASDキーで操作し、Fキーで弾を発射するようにしてみよう。

5. 自分だけのアイデアを加えて、オリジナルのシューティングゲームを作ってみよう。