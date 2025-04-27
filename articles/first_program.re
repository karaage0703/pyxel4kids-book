= 最初のプログラムを作ろう

//lead{
この章では、Pyxelを使った最初のプログラムを作成し、画面に文字や図形を表示します。
//}

== プログラムの作成手順

Pyxelでプログラムを作るときは、次の手順で進めます。

 1. エディタ（Visual Studio Code）を起動する
 2. 新しいファイルを作成する
 3. プログラムを書く
 4. ファイルを保存する
 5. プログラムを実行する

それでは、順番に進めていきましょう。

== エディタの起動とファイル作成

まずは、Visual Studio Code（VSCode）を起動します。

 1. スタートメニュー（Windowsの場合）またはアプリケーションフォルダ（Macの場合）から「Visual Studio Code」を探して起動します。
 2. 「ファイル」→「新規ファイル」を選びます。
 3. 「ファイル」→「保存」を選び、ファイル名を「hello_pyxel.py」として保存します。ファイル名の最後に「.py」をつけることで、Pythonのファイルであることを示します。

//image[vscode_new_file][新しいファイルの作成]{
//}

== 最初のプログラム

それでは、最初のプログラムを書いてみましょう。次のコードを入力してください。

//list[first_program][最初のPyxelプログラム][python]{
import pyxel

# Pyxelを初期化（画面の大きさを160x120ピクセルに設定）
pyxel.init(160, 120, title="はじめてのPyxel")

# 画面を更新する関数
def update():
    # ESCキーが押されたら終了
    if pyxel.btnp(pyxel.KEY_ESCAPE):
        pyxel.quit()

# 画面を描画する関数
def draw():
    # 画面を黒色（0）でクリア
    pyxel.cls(0)
    # 白色（7）で文字を表示
    pyxel.text(55, 41, "Hello, Pyxel!", 7)
    pyxel.text(31, 61, "はじめてのプログラミング", 10)
    pyxel.text(50, 81, "画面サイズ: 160x120", 11)

# Pyxelの実行（updateとdraw関数を渡す）
pyxel.run(update, draw)
//}

== プログラムの保存と実行

プログラムを入力したら、保存して実行しましょう。

 1. 「ファイル」→「保存」を選ぶか、Ctrl+S（Windowsの場合）またはCommand+S（Macの場合）を押して保存します。
 2. コマンドプロンプト（Windowsの場合）またはターミナル（Macの場合）を開きます。
 3. プログラムを保存したフォルダに移動します。
 4. 次のコマンドを入力して実行します。

//cmd{
# Windowsの場合
python hello_pyxel.py

# Macの場合
python3 hello_pyxel.py
//}

プログラムが正しく実行されると、黒い画面に「Hello, Pyxel!」などの文字が表示されます。ESCキーを押すと、プログラムが終了します。

//image[first_program_result][最初のプログラムの実行結果]{
//}

== プログラムの解説

最初のプログラムを詳しく見ていきましょう。

=== Pyxelの読み込みと初期化

//list[import_init][Pyxelの読み込みと初期化][python]{
import pyxel

# Pyxelを初期化（画面の大きさを160x120ピクセルに設定）
pyxel.init(160, 120, title="はじめてのPyxel")
//}

 * `import pyxel`：Pyxelを使うための準備をします。
 * `pyxel.init(160, 120, title="はじめてのPyxel")`：Pyxelを初期化します。
   * 最初の数字（160）は画面の幅（横幅）をピクセル単位で指定します。
   * 2番目の数字（120）は画面の高さをピクセル単位で指定します。
   * `title="はじめてのPyxel"`は、ウィンドウのタイトルを設定します。

=== update関数

//list[update_function][update関数][python]{
# 画面を更新する関数
def update():
    # ESCキーが押されたら終了
    if pyxel.btnp(pyxel.KEY_ESCAPE):
        pyxel.quit()
//}

 * `def update():`：「update」という名前の関数を定義します。この関数は、ゲームの状態を更新するために使われます。
 * `if pyxel.btnp(pyxel.KEY_ESCAPE):`：ESCキーが押されたかどうかをチェックします。
 * `pyxel.quit()`：Pyxelを終了します。

=== draw関数

//list[draw_function][draw関数][python]{
# 画面を描画する関数
def draw():
    # 画面を黒色（0）でクリア
    pyxel.cls(0)
    # 白色（7）で文字を表示
    pyxel.text(55, 41, "Hello, Pyxel!", 7)
    pyxel.text(31, 61, "はじめてのプログラミング", 10)
    pyxel.text(50, 81, "画面サイズ: 160x120", 11)
//}

 * `def draw():`：「draw」という名前の関数を定義します。この関数は、画面に絵を描くために使われます。
 * `pyxel.cls(0)`：画面を指定した色（ここでは0=黒）でクリアします。
 * `pyxel.text(55, 41, "Hello, Pyxel!", 7)`：文字を表示します。
   * 最初の数字（55）はX座標（左からの位置）を指定します。
   * 2番目の数字（41）はY座標（上からの位置）を指定します。
   * `"Hello, Pyxel!"`は表示するテキストです。
   * 最後の数字（7）は文字の色を指定します（7=白）。

=== Pyxelの実行

//list[run_pyxel][Pyxelの実行][python]{
# Pyxelの実行（updateとdraw関数を渡す）
pyxel.run(update, draw)
//}

 * `pyxel.run(update, draw)`：Pyxelを実行します。updateとdraw関数を渡して、ゲームループを開始します。

== Pyxelの色

Pyxelでは、0から15までの16色を使うことができます。それぞれの色には番号が割り当てられています。

//table[pyxel_colors][Pyxelの色]{
番号	色
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

色の番号を変えると、文字や図形の色を変えることができます。

== 座標系

Pyxelの画面では、左上が原点（0, 0）で、右に行くほどX座標が大きくなり、下に行くほどY座標が大きくなります。

//image[coordinate_system][Pyxelの座標系]{
//}

たとえば、160×120の画面の場合：
 * 左上の座標は（0, 0）
 * 右上の座標は（159, 0）
 * 左下の座標は（0, 119）
 * 右下の座標は（159, 119）

== プログラムの変更

プログラムを少し変更して、違う結果を見てみましょう。

=== 画面サイズの変更

画面のサイズを変更するには、`pyxel.init()`の引数を変更します。

//list[change_screen_size][画面サイズの変更][python]{
# 画面サイズを200x150に変更
pyxel.init(200, 150, title="はじめてのPyxel")
//}

=== 文字の位置と色の変更

文字の位置や色を変更するには、`pyxel.text()`の引数を変更します。

//list[change_text][文字の位置と色の変更][python]{
# 文字の位置と色を変更
pyxel.text(10, 10, "Hello, Pyxel!", 8)  # 赤色（8）で左上に表示
pyxel.text(50, 50, "こんにちは！", 10)  # 黄色（10）で中央に表示
//}

== まとめ

この章では、Pyxelを使った最初のプログラムを作成しました。

 * Pyxelプログラムの基本的な構造
 * 画面の初期化と設定
 * 文字の表示方法
 * 色の指定方法
 * 座標系の仕組み

次の章では、さまざまな図形を描く方法を学びます。

== チャレンジ問題

1. 画面サイズを変更して（例：240x180）、プログラムを実行してみよう。文字の位置も調整してみよう。

2. 自分の名前や好きな言葉を画面に表示するプログラムを作ってみよう。色や位置を工夫してみよう。

3. 背景色を変えてみよう。`pyxel.cls(0)`の0を別の数字（1〜15）に変えるとどうなるかな？