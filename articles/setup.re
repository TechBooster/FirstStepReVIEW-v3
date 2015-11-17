= 環境を整える

#@# NOTE author:vvakame

まずはRe:VIEWで執筆するための環境を整えましょう。

TechBoosterでは、GitHubが提供するエディタであるAtom@<fn>{atom}とそれに追加できるパッケージであるlanguage-review@<fn>{language-review}を使い執筆を行い、GitHubなどにpushする前にRuby版のRe:VIEW@<fn>{review}を使ってHTMLやPDFの生成チェックを行う運用になっています。
これは、language-reviewはreview.js@<fn>{review.js}というJavaScriptによるRe:VIEWの移植版を使っているためです。
review.jsは現在のところ、PDFを生成することなどができませんし、文章の解釈もRuby版と厳密には一致しません。

本書執筆時点での各ツールのバージョンは次のとおり。

 * Atom v1.2.0
 * language-review 0.12.4
 * Re:VIEW 1.7.0 または review-peg 0.1.3

//footnote[atom][@<href>{https://atom.io/}]
//footnote[language-review][@<href>{https://atom.io/packages/language-review}]
//footnote[review][@<href>{https://github.com/kmuto/review}]
//footnote[review.js][@<href>{https://github.com/vvakame/review.js}]

== Atom+language-reviewでエディタを整える

#@# NOTE author:vvakame

まずは、GitHubが作っているエディタであるAtomをインストールします。

インストールしたらAtomを立ち上げ、設定からlanguage-reviewをインストールします（@<img>{install-language-review}）。
もしくは、一度Atomを起動するとMac OS Xであれば@<code>{/usr/local/bin/}にapmコマンドがインストールされますので、@<code>{apm install language-review}とします。

//image[install-language-review][language-reviewをインストールする]{
//}

次に、適当な名前の.reファイルを作ります。
ここではtest.reとします。
このファイルを開くと、デフォルトでは編集モードがRe:VIEW以外になっているため、クリックして@<fn>{atom-tips}Re:VIEWに切り替えます（@<img>{language-review-grammar1}、@<img>{language-review-grammar2}@<fn>{atom-images-disclaimer}）。

//image[language-review-grammar1][モード切り替え前]{
//}
//image[language-review-grammar2][このように切り替えるのだ]{
//}

パッケージのインストール後に依存する別パッケージ（linter）のインストールを行うため、動作がおかしい気がする場合Atomを一旦完全に終了させてから起動しなおしてみてください。

また、人柱用ですがMac OS X環境ではAtomのインストールからlanguage-reviewの導入までを行うインストールスクリプトを用意してあります。

//emlist{
curl -L https://github.com/vvakame/language-review/raw/master/install.sh | bash
//}

Atomとlanguage-reviewは便利な機能を持っています。
よく使うのは次のとおり。

 * シンタックスハイライト
 * 文法ミスの警告
 * 文章の校正支援
 * HTMLプレビュー
 * Re:VIEWの記法一覧
 * アウトライン表示とジャンプ

//footnote[atom-tips][Mac OS Xの場合、Command+Shift+Pでコマンドパレットが開くのでgrammarなどそれっぽいワードを投げ込むとマウスなしで操作できます。]
//footnote[atom-images-disclaimer][プラグインの導入状態やAtomのバージョンによって、画像どおりの見た目じゃない場合のほうが多いはずです。]

== Re:VIEWのインストール

#@# NOTE author:vvakame

次に、Ruby版Re:VIEWをインストールします。
PDFやepubの生成などの最終出力を行うのに必要なので、重要です。

RubyとRubyGemsはすでに利用可能な環境になっているものとします。
インストールは単に次のコマンドを実行するだけです@<fn>{experimental-review}。Rubyのインストール方法次第ではsudoが必要かもしれません。

//emlist{
$ gem install review
//}

これだけです。
詳しい使い方は@<chapref>{review-introduction}で解説します。

//footnote[experimental-review][review-pegという実験的パッケージがありますが熱心なRe:VIEW信者でない限りreviewを使えばよいでしょう]

===[column] Ruby導入の手引き Mac OS X or Linux編

TODO vvakame

===[/column]

===[column] Ruby導入の手引き Windows編

TODO vvakame

===[/column]

== PDF出力の準備

#@# NOTE author:vvakame

PDF出力の準備をします。
Re:VIEW文書をPDFに変換するにはLaTeX（platexまたはlualatexなど）を使います。
review形式→reviewツール実行→latex形式→platex実行→PDF という流れです。

=== Mac OS Xの場合

MacTeX@<fn>{mactex}を使いましょう。

//footnote[mactex][@<href>{https://www.tug.org/mactex/}]

=== Linuxの場合

texliveパッケージを利用します。
Ubuntu、Debianともに次のコマンドで導入できます。

//emlist{
$ sudo apt-get install texlive-lang-cjk texlive-fonts-recommended
//}

=== Windowsの場合

LaTeX環境の構築の難易度が高いため、Dockerを使うなどしてください。

==[column] Dockerを使ってどこでもビルド

Ruby入れたりTeX入れたりめんどくさすぎる！
という人のために、Dockerのイメージを用意@<fn>{docker-review}してあります。

//emlist{
$ docker run -i -t vvakame/review -v $(pwd):/book /bin/bash
//}

コマンドを実行すると、reviewとlatexの実行環境が整った状態の環境が使えます。
コマンド実行時のディレクトリが /book にマウントされるので、適宜コンパイル用のコマンドを実行してください。

TODO vvakame サンプルプロジェクトを用意する

==[/column]

//footnote[docker-review][@<href>{https://hub.docker.com/r/vvakame/review/}]

== 推奨するディレクトリ構成

#@# NOTE author:vvakame

TechBoosterが推奨するディレクトリ構成を述べておきます。
要点は次のとおりです。
具体的には@<list>{directory}となります。

 * リポジトリのトップレベルにはファイルをあまり散らかさない
 * 複数人で執筆した時にそれぞれのファイルが混ざったり邪魔になったりしないようにする
 * 著者全員で利用するreviewのバージョンを固定する
 * ビルド手順を統一するために何らかのタスクランナーを使う（TechBoosterの場合Node.js+grunt）

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

== トラブルシューティング

TODO mhidaka
