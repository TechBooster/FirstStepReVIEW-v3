= 役に立つ豆知識

技術書を作る際に詰まる部分をまとめました。
知らなければたどり着かない知識や、ちょっとした工夫など便利なテクニックを紹介します。

== 推奨するディレクトリ構成

#@# NOTE author:vvakame

TechBoosterが推奨するディレクトリ構成を述べておきます。
要点は次のとおりです。
具体的には@<list>{directory}となります。

 * リポジトリのトップレベルにはファイルをあまり散らかさない
 * 複数人で執筆した時にそれぞれのファイルが混ざったり邪魔になったりしないようにする
 * 著者全員で利用するreviewのバージョンを固定する
 * ビルド手順を統一するために何らかのタスクランナーを使う（TechBoosterの場合、Node.js+grunt）

//list[directory][ディレクトリ構成]{
  ├── README.md
  ├── circle.yml            （CIサービスであるCircle CIの設定ファイル）
  ├── setup.sh              （執筆を始めるためにgemやnpmのインストールを行うスクリプト）
  ├── Gemfile               （bundler経由でRe:VIEWを利用するための設定ファイル）
  ├── Gemfile.lock          （bundlerでインストールするライブラリのバージョンをロックする）
  ├── package.json          （gruntを利用するためのnpm用設定ファイル）
  ├── npm-shrinkwrap.json   （npmでインストールするライブラリのバージョンをロックする）
  ├── Gruntfile.js          （gruntの動作設定ファイル）
  ├── articles
  │   ├── catalog.yml       （Re:VIEW用 章立ての設定ファイル）
  │   ├── config.yml        （Re:VIEW用 本を生成する時のメタデータ記述ファイル）
  │   ├── prh.yml           （language-review用校正設定ファイル）
  │   ├── preface.re
  │   ├── foo.re
  │   ├── bar.re
  │   ├── contributors.re
  │   ├── images
  │   │   ├── foo           （foo.re用）
  │   │   │   └── description-of-foo.png
  │   │   └── bar           （bar.re用）
  │   │       └── bar-introduction.png
  │   ├── layouts           （存在しない場合もある）
  │   │   └── 省略
  │   └── sty               （存在しない場合もある）
  │       └── 省略
  └── code                  （サンプルコード置き場）
      ├── foo               （foo.re用）
      │   └── sample.js
      └── bar               （bar.re用）
          └── flush.js
//}

原稿はarticlesディレクトリに、サンプルコードはcodeディレクトリに入れています。
articles/imagesやcodeの中は、原稿の章ごとに.reのファイル名と同名のディレクトリを用意し、その中で活動します。

原稿のファイル名は、わかりやすいのが一番！ということで複数名で執筆する場合筆者の名前にしてしまう場合があります。
vvakame.reというファイル名にしてしまえば、レビューを行ったりビルドエラーなどの問題が発生した時連絡する人がわかりやすい。
という発想です。

=={config_task_runner} タスクランナーの設定

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

== HTMLの生成方法

Re:VIEWでは.reファイルからHTMLを出力することができます。
@<hd>{review-introduction|how_to_compile}でも少し触れていますが、
HTMLを出力するには@<code>{review-compile}コマンドに@<code>{--target}オプションで@<code>{html}を指定します。

次のコマンドはHTMLへのコンパイル結果を標準出力に出力するだけの、最も単純なケースです。

//cmd{
review-compile --target=html tips.re
//}

実際のユースケースでは、保存先のパスを指定したり、CSSファイルを設定したりするでしょう。
HTMLのバージョンを指定することもできます。
@<code>{＠<chapref>{chapter\}}や@<code>{＠<hd>{head\}}などの章・見出しの参照をリンクにする@<code>{--chapterlink}というオプションもあります。

//cmd{
review-compile --target=html --stylesheet=base.css,style.css --htmlversion=5 \
--chapterlink --output=tips.html tips.re
//}

CSSファイルやHTMLのバージョンは、@<hd>{review-introduction|config_yml}で解説したconfig.ymlにも記述できます。
@<code>{--yaml}オプションでconfig.ymlを指定しましょう。

//cmd{
review-compile --target=html --yaml=config.yml --output=tips.html tips.re
//}

=== 複数のファイルをHTML化する

複数のファイルを一気にHTMLにコンパイルすることもできます。
@<code>{--all}オプションを使えば、カレントディレクトリの.reファイルをすべて同名の.htmlファイルにコンパイルします。

//cmd{
cd articles/
review-compile --target=html --all
//}

しかし、これだけでは個々の.reファイルがそれぞれHTMLファイルになるだけです。
ある章のHTMLを読み終えたら次のHTMLへ…という具合にリンクが欲しいと思いませんか。

@<hd>{review-introduction|紙面レイアウトを変更する}ではlayout.tex.erbファイルを用意することで、
Re:VIEWが出力するLaTeXソースファイルの構成を変更する方法を紹介しています。
HTMLファイルについても同様の手順でカスタマイズできます。

@<list>{layout_html_erb}は、.reファイルなどがあるディレクトリの下に@<code>{layouts/layout.html.erb}というパスで配置するテンプレートの例です。
Re:VIEWが生成する本文（@<code>{body}）の前後に「前へ」「次へ」というリンクを追加しています。
章の順番はカレントディレクトリにあるcatalog.ymlファイルか、@<code>{--catalogfile}オプションで指定したYAMLファイルで決定します。
catalog.ymlについての説明は@<hd>{review-introduction|catalog_yml}を参照してください。

//list[layout_html_erb][layouts/layout.html.erb]{
#@mapfile(../code/tips/layout.html.erb)
<!DOCTYPE html>
<html lang="ja">
<head>
  <meta charset="utf-8">
<% book = @builder.instance_variable_get(:@book) %>
<% book.config["stylesheet"].each do |style| %>
  <link rel="stylesheet" type="text/css" href="<%= style %>" />
<% end %>
  <title><%= title %></title>
</head>
<body>
<% if @prev.present? %><a href='<%= @prev.id %>.html'>前へ</a><% end %>
<%= body %>
<% if @next.present? %><a href='<%= @next.id %>.html'>次へ</a><% end %>
</body>
</html>
#@end
//}

@<list>{layout_html_erb}は、筆者の一人であるvvakameが執筆したTypeScript in Definitelyland（@<fn>{typescript-in-definitelyland}）のWeb公開版のソースを参考にしています。
Re:VIEWで執筆した原稿を実際にHTMLで公開している例として一度目を通すと面白いでしょう。

//footnote[typescript-in-definitelyland][@<href>{https://github.com/typescript-ninja/typescript-in-definitelyland}]

== epubの生成方法とか

TODO mstssk

== 関連各所の紹介
TechBoosterがRe:VIEWを使っているなかで関係したお世話になっている各所を紹介します。

 * 達人出版会：Re:VIEWを使った電子書籍を扱う出版社
 * トップスタジオ：Re:VIEWによるリフロー（自動組版）を導入している制作会社
 * 日光企画：お世話になっている印刷所

 ありがとう！そしてありがとう！！

== 品質を高めるためのチェックポイント

限られた時間のなかで可能な限り品質を確保するポイントをリスト形式で紹介します。

 * 企画は書きたいことを選ぶ（モチベーション維持）
 * 一人でかかない（共同執筆がお勧め）
 * 執筆時点は早めの締め切りを設定する（こうしておくと致命傷で済む）
 * レビューを実施する（読者の視点を作り出す）
 * 紙面を=や*で検索する（文法ミスを見つけるため）
 * 記号などの文字化け探し（TeX、フォントはUTF-8対応しているとは限らない）
 * 紙面のはみ出しチェック（TeXコンパイルのtoo lateという文字列を確認する）

実際には何度も読みなおし文章を推敲することが一番ですが、このようなステップを意識することで
ケアレスミスを見つけられます（特にツールに不慣れな場合は有効です）。
