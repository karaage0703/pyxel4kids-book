= 音を鳴らしてみよう

//lead{
この章では、Pyxelを使って効果音やBGM（バックグラウンドミュージック）を再生する方法を学びます。
//}

== ゲームの音の重要性

ゲームには、画面に表示される映像だけでなく、音も重要な要素です。効果音やBGMがあることで、ゲームはより楽しく、臨場感のあるものになります。

Pyxelでは、レトロゲーム風の8ビットサウンドを簡単に作成して再生することができます。

== Pyxelのサウンド機能

Pyxelには、次の2種類のサウンド機能があります。

 1. 効果音（Sound Effects）：短い音を鳴らす機能
 2. BGM（Background Music）：複数の効果音を組み合わせて、曲を作る機能

これらの機能を使って、ゲームに音を追加していきましょう。

== 効果音を鳴らす

まずは、効果音を鳴らす方法を学びましょう。効果音を鳴らすには、次の手順が必要です。

 1. 効果音を定義する
 2. 効果音を再生する

=== 効果音の定義

効果音は、`sound`関数を使って定義します。

//list[define_sound][効果音の定義][python]{
# 効果音の定義
pyxel.sound(0).set(
    note="C3 C4 C5",  # 音階
    tone="T",         # 音色（T:三角波、S:矩形波、P:パルス波、N:ノイズ）
    volume="7",       # 音量（0～7）
    effect="N",       # エフェクト（N:なし、S:スライド、V:ビブラート、F:フェードアウト）
    speed=20          # 再生速度（数値が大きいほど遅い）
)
//}

この例では、「C3」「C4」「C5」という3つの音階を順番に鳴らす効果音を定義しています。

=== 効果音の再生

定義した効果音は、`play`関数を使って再生します。

//list[play_sound][効果音の再生][python]{
# 効果音の再生
pyxel.play(0, 0)  # チャンネル0で、サウンド番号0を再生
//}

`play`関数の引数は次のとおりです。

 * 第1引数：チャンネル番号（0～3）
 * 第2引数：サウンド番号（`sound`関数で定義した番号）

== 基本的なプログラム構造

効果音を使った基本的なプログラム構造を確認しましょう。

//list[basic_structure][基本的なプログラム構造][python]{
import pyxel

# Pyxelを初期化
pyxel.init(160, 120, title="音を鳴らそう")

# 効果音の定義
pyxel.sound(0).set(
    note="C3 C4 C5",
    tone="T",
    volume="7",
    effect="N",
    speed=20
)

# 画面を更新する関数
def update():
    # ESCキーが押されたら終了
    if pyxel.btnp(pyxel.KEY_ESCAPE):
        pyxel.quit()

    # スペースキーが押されたら効果音を再生
    if pyxel.btnp(pyxel.KEY_SPACE):
        pyxel.play(0, 0)

# 画面を描画する関数
def draw():
    # 画面を黒色（0）でクリア
    pyxel.cls(0)

    # 操作方法を表示
    pyxel.text(30, 60, "Press SPACE to play sound", 7)

# Pyxelの実行
pyxel.run(update, draw)
//}

このプログラムをファイル名「sound.py」として保存し、実行してみましょう。スペースキーを押すと、効果音が鳴ります。

== 様々な効果音

Pyxelでは、音階、音色、音量、エフェクト、再生速度を変えることで、様々な効果音を作ることができます。

=== 音階（note）

音階は、「C（ド）」「D（レ）」「E（ミ）」「F（ファ）」「G（ソ）」「A（ラ）」「B（シ）」の7つの音と、その派生音（「C#」「D#」など）を使って指定します。数字は音の高さ（オクターブ）を表し、数字が大きいほど高い音になります。

//list[note_example][音階の例][python]{
# 上昇音
pyxel.sound(0).set(note="C3 D3 E3 F3 G3 A3 B3 C4", tone="T", volume="7", effect="N", speed=10)

# 下降音
pyxel.sound(1).set(note="C5 B4 A4 G4 F4 E4 D4 C4", tone="T", volume="7", effect="N", speed=10)

# ドレミファソラシド
pyxel.sound(2).set(note="C4 D4 E4 F4 G4 A4 B4 C5", tone="T", volume="7", effect="N", speed=10)
//}

=== 音色（tone）

音色は、次の4種類から選べます。

 * T：三角波（柔らかい音）
 * S：矩形波（はっきりした音）
 * P：パルス波（鋭い音）
 * N：ノイズ（雑音）

//list[tone_example][音色の例][python]{
# 三角波
pyxel.sound(0).set(note="C4 E4 G4", tone="T", volume="7", effect="N", speed=10)

# 矩形波
pyxel.sound(1).set(note="C4 E4 G4", tone="S", volume="7", effect="N", speed=10)

# パルス波
pyxel.sound(2).set(note="C4 E4 G4", tone="P", volume="7", effect="N", speed=10)

# ノイズ
pyxel.sound(3).set(note="C4 E4 G4", tone="N", volume="7", effect="N", speed=10)
//}

=== 音量（volume）

音量は、0から7までの数字で指定します。数字が大きいほど音が大きくなります。

//list[volume_example][音量の例][python]{
# 大きい音
pyxel.sound(0).set(note="C4 E4 G4", tone="T", volume="7", effect="N", speed=10)

# 中くらいの音
pyxel.sound(1).set(note="C4 E4 G4", tone="T", volume="4", effect="N", speed=10)

# 小さい音
pyxel.sound(2).set(note="C4 E4 G4", tone="T", volume="1", effect="N", speed=10)
//}

=== エフェクト（effect）

エフェクトは、次の4種類から選べます。

 * N：なし（通常の再生）
 * S：スライド（音が滑らかにつながる）
 * V：ビブラート（音が揺れる）
 * F：フェードアウト（音が徐々に小さくなる）

//list[effect_example][エフェクトの例][python]{
# エフェクトなし
pyxel.sound(0).set(note="C4 E4 G4", tone="T", volume="7", effect="N", speed=10)

# スライド
pyxel.sound(1).set(note="C4 E4 G4", tone="T", volume="7", effect="S", speed=10)

# ビブラート
pyxel.sound(2).set(note="C4 E4 G4", tone="T", volume="7", effect="V", speed=10)

# フェードアウト
pyxel.sound(3).set(note="C4 E4 G4", tone="T", volume="7", effect="F", speed=10)
//}

=== 再生速度（speed）

再生速度は、数値で指定します。数値が小さいほど速く再生され、大きいほど遅く再生されます。

//list[speed_example][再生速度の例][python]{
# 速い
pyxel.sound(0).set(note="C4 E4 G4", tone="T", volume="7", effect="N", speed=5)

# 普通
pyxel.sound(1).set(note="C4 E4 G4", tone="T", volume="7", effect="N", speed=10)

# 遅い
pyxel.sound(2).set(note="C4 E4 G4", tone="T", volume="7", effect="N", speed=20)
//}

== ゲームに効果音を追加する

前の章で作ったキャラクター移動のプログラムに、効果音を追加してみましょう。

//list[add_sound_to_game][ゲームに効果音を追加する][python]{
import pyxel

# Pyxelを初期化
pyxel.init(160, 120, title="キャラクターと音")

# キャラクターの位置
player_x = 80
player_y = 60

# 効果音の定義
# 移動音
pyxel.sound(0).set(note="C3", tone="P", volume="3", effect="N", speed=5)
# ジャンプ音
pyxel.sound(1).set(note="C5 G4", tone="S", volume="4", effect="N", speed=10)
# アイテム取得音
pyxel.sound(2).set(note="C4 E4 G4 C5", tone="T", volume="5", effect="N", speed=5)

# 画面を更新する関数
def update():
    global player_x, player_y

    # ESCキーが押されたら終了
    if pyxel.btnp(pyxel.KEY_ESCAPE):
        pyxel.quit()

    # キーボード入力の受け付け
    if pyxel.btn(pyxel.KEY_LEFT):
        player_x -= 2
        pyxel.play(0, 0)  # 移動音を再生

    if pyxel.btn(pyxel.KEY_RIGHT):
        player_x += 2
        pyxel.play(0, 0)  # 移動音を再生

    if pyxel.btn(pyxel.KEY_UP):
        player_y -= 2
        pyxel.play(0, 0)  # 移動音を再生

    if pyxel.btn(pyxel.KEY_DOWN):
        player_y += 2
        pyxel.play(0, 0)  # 移動音を再生

    # スペースキーでジャンプ音
    if pyxel.btnp(pyxel.KEY_SPACE):
        pyxel.play(1, 1)  # ジャンプ音を再生

    # Zキーでアイテム取得音
    if pyxel.btnp(pyxel.KEY_Z):
        pyxel.play(2, 2)  # アイテム取得音を再生

    # 画面の端での処理
    if player_x < 10:
        player_x = 10
    if player_x > 150:
        player_x = 150
    if player_y < 10:
        player_y = 10
    if player_y > 110:
        player_y = 110

# 画面を描画する関数
def draw():
    # 画面を黒色（0）でクリア
    pyxel.cls(0)

    # キャラクターを描画
    pyxel.circ(player_x, player_y, 10, 7)

    # 操作方法を表示
    pyxel.text(5, 5, "Arrow keys: Move", 7)
    pyxel.text(5, 15, "Space: Jump sound", 7)
    pyxel.text(5, 25, "Z: Item sound", 7)

# Pyxelの実行
pyxel.run(update, draw)
//}

このプログラムでは、次の効果音を追加しています。

 * 矢印キーを押したときに移動音が鳴る
 * スペースキーを押したときにジャンプ音が鳴る
 * Zキーを押したときにアイテム取得音が鳴る

== BGMを作る

BGM（バックグラウンドミュージック）は、複数の効果音を組み合わせて作ります。BGMを作るには、次の手順が必要です。

 1. 効果音を定義する
 2. BGMを定義する
 3. BGMを再生する

=== BGMの定義

BGMは、`music`関数を使って定義します。

//list[define_music][BGMの定義][python]{
# 効果音の定義
pyxel.sound(0).set(note="C3 C4 C5", tone="T", volume="7", effect="N", speed=20)
pyxel.sound(1).set(note="E3 E4 E5", tone="S", volume="6", effect="N", speed=20)
pyxel.sound(2).set(note="G3 G4 G5", tone="P", volume="5", effect="N", speed=20)

# BGMの定義
pyxel.music(0).set(
    [0, 1, 2],  # トラック0, 1, 2を使用
    [           # 各トラックの再生パターン
        [0, 1],  # トラック0: サウンド0, 1を順番に再生
        [2, 0],  # トラック1: サウンド2, 0を順番に再生
        [1, 2]   # トラック2: サウンド1, 2を順番に再生
    ]
)
//}

=== BGMの再生

定義したBGMは、`playm`関数を使って再生します。

//list[play_music][BGMの再生][python]{
# BGMの再生
pyxel.playm(0)  # ミュージック番号0を再生
//}

== BGMを使ったプログラム

BGMを使った簡単なプログラムを作ってみましょう。

//list[music_program][BGMを使ったプログラム][python]{
import pyxel

# Pyxelを初期化
pyxel.init(160, 120, title="BGMを鳴らそう")

# 効果音の定義
# メロディ
pyxel.sound(0).set(note="C4 D4 E4 F4", tone="T", volume="7", effect="N", speed=10)
pyxel.sound(1).set(note="G4 A4 B4 C5", tone="T", volume="7", effect="N", speed=10)
# ベース
pyxel.sound(2).set(note="C3 C3 C3 C3", tone="S", volume="5", effect="N", speed=10)
pyxel.sound(3).set(note="G2 G2 G2 G2", tone="S", volume="5", effect="N", speed=10)
# ドラム
pyxel.sound(4).set(note="F2 F2 F2 F2", tone="N", volume="3", effect="N", speed=10)

# BGMの定義
pyxel.music(0).set(
    [0, 1, 2],  # トラック0, 1, 2を使用
    [
        [0, 1],  # トラック0: メロディ
        [2, 3],  # トラック1: ベース
        [4, 4]   # トラック2: ドラム
    ]
)

# BGM再生フラグ
bgm_playing = False

# 画面を更新する関数
def update():
    global bgm_playing

    # ESCキーが押されたら終了
    if pyxel.btnp(pyxel.KEY_ESCAPE):
        pyxel.quit()

    # スペースキーでBGMの再生/停止を切り替え
    if pyxel.btnp(pyxel.KEY_SPACE):
        if bgm_playing:
            pyxel.stop()  # BGMを停止
            bgm_playing = False
        else:
            pyxel.playm(0)  # BGMを再生
            bgm_playing = True

# 画面を描画する関数
def draw():
    # 画面を黒色（0）でクリア
    pyxel.cls(0)

    # 操作方法と状態を表示
    pyxel.text(30, 50, "Press SPACE to toggle BGM", 7)

    if bgm_playing:
        pyxel.text(50, 70, "BGM: Playing", 11)
    else:
        pyxel.text(50, 70, "BGM: Stopped", 8)

# Pyxelの実行
pyxel.run(update, draw)
//}

このプログラムでは、スペースキーを押すとBGMの再生/停止を切り替えることができます。

== まとめ

この章では、Pyxelを使って効果音やBGMを再生する方法を学びました。

 * 効果音の定義と再生方法
 * 音階、音色、音量、エフェクト、再生速度の設定方法
 * ゲームに効果音を追加する方法
 * BGMの定義と再生方法

音を追加することで、ゲームはより楽しく、臨場感のあるものになります。次の章では、これまで学んだ知識を使って、簡単なゲームを作ります。

== チャレンジ問題

1. 自分だけの効果音を作ってみよう。音階、音色、音量、エフェクト、再生速度を変えて、いろいろな音を試してみよう。

2. 前の章で作ったキャラクター移動のプログラムに、次の効果音を追加してみよう。
   * 画面の端に到達したときの効果音
   * キャラクターが特定の位置に来たときの効果音

3. 自分だけのBGMを作ってみよう。複数の効果音を組み合わせて、短い曲を作ってみよう。