= 開発環境をセットアップしよう

//lead{
この章では、PythonとPyxelをパソコンにインストールする方法を学びます。
//}

== 準備するもの

プログラミングを始める前に、次のものを準備しましょう。

 * パソコン（WindowsかMac）
 * インターネット接続
 * 大人の人の手伝い（必要に応じて）

インストール作業は少し難しいかもしれません。分からないことがあれば、お家の人や先生に手伝ってもらいましょう。

== Pythonのインストール

まずは、Pythonをインストールします。Pythonは無料で使えるプログラミング言語です。

=== Windowsの場合

//image[python_windows][Windowsでのインストール画面]{
//}

 1. インターネットブラウザで「Python ダウンロード」と検索するか、https://www.python.org/downloads/ にアクセスします。
 2. 「Download Python 3.x.x」（xは数字）というボタンをクリックします。
 3. ダウンロードしたファイル（python-3.x.x-amd64.exe）をダブルクリックします。
 4. 「Add Python 3.x to PATH」にチェックを入れます。これは重要です！
 5. 「Install Now」をクリックします。
 6. インストールが完了したら「Close」をクリックします。

=== Macの場合

//image[python_mac][Macでのインストール画面]{
//}

 1. インターネットブラウザで「Python ダウンロード」と検索するか、https://www.python.org/downloads/ にアクセスします。
 2. 「Download Python 3.x.x」（xは数字）というボタンをクリックします。
 3. ダウンロードしたファイル（python-3.x.x-macos11.pkg）をダブルクリックします。
 4. 画面の指示に従ってインストールします。
 5. インストールが完了したら「閉じる」をクリックします。

== Pythonのインストール確認

Pythonがきちんとインストールされたか確認しましょう。

=== Windowsの場合

 1. スタートメニューから「コマンドプロンプト」を探して開きます。
 2. 開いたウィンドウに「python --version」と入力して、Enterキーを押します。
 3. 「Python 3.x.x」（xは数字）と表示されれば成功です。

//image[python_check_windows][Windowsでのインストール確認]{
//}

=== Macの場合

 1. Finderから「アプリケーション」→「ユーティリティ」→「ターミナル」を開きます。
 2. 開いたウィンドウに「python3 --version」と入力して、Enterキーを押します。
 3. 「Python 3.x.x」（xは数字）と表示されれば成功です。

//image[python_check_mac][Macでのインストール確認]{
//}

== Pyxelのインストール

次に、Pyxelをインストールします。Pyxelは、Pythonのコマンドを使ってインストールします。

=== Windowsの場合

 1. コマンドプロンプトを開きます（まだ開いていない場合）。
 2. 次のコマンドを入力して、Enterキーを押します。

//cmd{
pip install -U pyxel
//}

=== Macの場合

 1. ターミナルを開きます（まだ開いていない場合）。
 2. 次のコマンドを入力して、Enterキーを押します。

//cmd{
pip3 install -U pyxel
//}

`error: externally-managed-environment`というエラーが出たら以下をためしてください。

//cmd{
pip3 install -U pyxel --break-system-packages
//}

== Pyxelのインストール確認

Pyxelがきちんとインストールされたか確認しましょう。

=== Windowsの場合

 1. コマンドプロンプトで次のコマンドを入力して、Enterキーを押します。

//cmd{
python -m pyxel.examples.01_hello_pyxel
//}

=== Macの場合

 1. ターミナルで次のコマンドを入力して、Enterキーを押します。

//cmd{
python3 -m pyxel.examples.01_hello_pyxel
//}

どちらの場合も、黒い画面に「Hello, Pyxel!」という文字が表示されれば成功です。ESCキーを押すと、画面が閉じます。

//image[pyxel_check][Pyxelのインストール確認]{
//}

== プログラムを書くためのエディタ

プログラムを書くには、「エディタ」というソフトウェアを使います。メモ帳でも書けますが、専用のエディタを使うと便利です。ここでは、「Visual Studio Code（VSCode）」というエディタをおすすめします。

=== Visual Studio Codeのインストール

 1. インターネットブラウザで「Visual Studio Code ダウンロード」と検索するか、https://code.visualstudio.com/ にアクセスします。
 2. 「Download for Windows」または「Download for Mac」ボタンをクリックします。
 3. ダウンロードしたファイルをダブルクリックして、画面の指示に従ってインストールします。

//image[vscode][Visual Studio Codeの画面]{
//}

== まとめ

この章では、PythonとPyxelをインストールする方法を学びました。

 * Pythonは公式サイトからダウンロードしてインストール
 * Pyxelはコマンドでインストール
 * プログラムを書くためのエディタとしてVisual Studio Codeがおすすめ

次の章では、最初のPyxelプログラムを書いてみましょう。

== チャレンジ問題

1. Pyxelのサンプルプログラムを他にも実行してみよう。次のコマンドを試してみてください。

//cmd{
# Windowsの場合
python -m pyxel.examples.02_jump_game
python -m pyxel.examples.03_draw_api

# Macの場合
python3 -m pyxel.examples.02_jump_game
python3 -m pyxel.examples.03_draw_api
//}

2. Visual Studio Codeを起動して、新しいファイルを作ってみよう。「ファイル」→「新規ファイル」を選んで、何か文字を入力してみましょう。