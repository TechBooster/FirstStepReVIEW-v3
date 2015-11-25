= 役に立つ豆知識

TODO mhidaka

== タスクランナーの設定

#@# NOTE author:vvakame

複数人で執筆する場合、何らかの統一された手順でのビルド手順が必要です。
TechBoosterではNode.js+gruntを利用しています。
この構成になっているのは、プロジェクト構成を主に行っているvvakameが一番使い慣れているから、という理由が大きいです。

新規に書き起こすのであれば、執筆者があまり導入の手間をかけなくてもよいものを選ぶのがよいでしょう。
候補としては、Rubyはすでに入っているはずなのでrakeを使うか、色々なOS・環境で導入済みである場合の多いJavaと、gradle@<fn>{why-gradle}の組み合わせがよいかもしれません。

タスクランナーが行うべき作業は少ないです。

 * 古い生成ファイルを消す（消さないとエラーになる場合がある）
 * review-preprocコマンドを実行する
 * 各ターゲット向けのビルド用コマンドを実行する

これだけです。

ひとつひとつ、どういうコマンドと等価な処理をしていけばよいかを解説します。

 * 古い生成ファイルを消す（消さないとエラーになる場合がある）

最低限必要なのは次のコマンドと同様の動作です。

//emlist{
rm -rf articles/C89-FirstStepReVIEW-v2-pdf/ \
       articles/*.pdf  \
       articles/*.epub \
       articles/*.html \
       articles/*.xml  \
       articles/*.txt
//}

#@# prh:disable
それぞれ、pdf、epub、html、idgxml（Adobe InDesign用XML）、text生成時に作成される一時ファイルまたは最終出力ファイルです。
一番最初の行の C89-FirstStepReVIEW-v2-pdf 部分はarticles/config.ymlのbooknameの設定により変化します。
特に、最初の行は必ず行わないとPDFを生成しようとした時にエラーになるのでPDF生成処理前には必ず消すようにします。

 * review-preprocコマンドを実行する

最低限必要なのは次のコマンドの実行です。

//emlist{
# articlesディレクトリ内で実行する想定
$ review-preproc -r --tabwidth=2 *.re
//}

review-preprocコマンドはRe:VIEWの仕組みの中で、もっとも便利な、愛すべきコマンドといえます。
review-preprocコマンドは文書中に埋め込まれたpragmaを処理し、サンプルコードを文書中に展開したり指定のコマンドの実行結果を文書中に展開してくれたりします。
C言語のマクロとだいたい同じものだと思えばよいでしょう。

文書にソースコードを貼りこむ時、インデントは2スペースとします。
このため、4スペース派の人はサンプルコードではタブを使うようにして、エディタ上では1タブ＝4スペースで作業し、文書中に貼りこむ時にタブを2スペースに変換するとよいでしょう。

詳細は@<chapref>{review-introduction}に譲ります。

 * 各ターゲット向けのビルド用コマンドを実行する

最低限必要なのは次のコマンドの実行です。

//emlist{
# 全て、articlesディレクトリ内で実行する想定
# textの生成
$ review-compile --all --target=text
# htmlの生成
$ review-compile --all --target=html --stylesheet=style.css --chapterlink
# latexの生成
$ review-compile --all --target=latex --footnotetext
# idgxmlの生成
$ review-compile --all --target=idgxml
# pdfの生成
$ review-pdfmaker-peg config.yml
# epubの生成
$ review-epubmaker-peg config.yml
//}

欲しい出力結果に応じて、コマンドを使い分けます。
pdf、epubについては利用するコマンドそのものが違うので注意します。

これらを詰め込んだ、実際にTechBoosterで使っているgrunt用設定ファイルを公開しています。

TODO vvakame サンプルプロジェクトを用意する

//footnote[why-gradle][gradleはgradle wrapperという仕組みがあり、gradle自体を別途導入する必要がないため]

== Webページの生成方法とか

TODO mstssk

== epubの生成方法とか

TODO mstssk

== 関連各所の紹介？達人出版会とかトップスタジオとか？

TODO mhidaka

== 品質を高めるためのチェックポイント

TODO mhidaka
