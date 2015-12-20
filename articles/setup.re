= 環境を整える

#@# NOTE author:vvakame

まずはRe:VIEWで執筆するための環境を整えましょう。

TechBoosterでは、GitHubが提供するエディタであるAtom@<fn>{atom}と追加パッケージであるlanguage-review@<fn>{language-review}を使い執筆を行います。
そしてGitHubなどにpushする前にRuby版のRe:VIEW@<fn>{review}を使ってHTMLやPDFの生成チェックを行う運用になっています。
これは、language-reviewはreview.js@<fn>{review.js}というJavaScriptによるRe:VIEWの移植版を使っているためです。
review.jsは現在のところ、PDFを生成することなどができませんし、文章の解釈もRuby版と厳密には一致しません。

本書執筆時点での各ツールのバージョンは次のとおり。

#@# TODO 入稿前にここのバージョンを再確認すること

 * Atom v1.3.2
 * language-review 0.12.4
 * Re:VIEW 1.7.1 または review-peg 0.2.2

//footnote[atom][@<href>{https://atom.io/}]
//footnote[language-review][@<href>{https://atom.io/packages/language-review}]
//footnote[review][@<href>{https://github.com/kmuto/review}]
//footnote[review.js][@<href>{https://github.com/vvakame/review.js}]

== Atomとlanguage-reviewでエディタを用意する

#@# NOTE author:vvakame

GitHubが作っているエディタであるAtomをインストールします。

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

パッケージのインストール時に依存する別パッケージ（linter）のインストールも行っています。動作がおかしい気がする場合Atomを完全に終了させてから起動しなおしてみてください。

また人柱用ですがMac OS X環境ではAtomのインストールからlanguage-reviewの導入までを行うインストールスクリプトを用意してあります。

//cmd{
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

@<img>{language-review-sample}がサンプルです。

//image[language-review-sample][language-reviewの画面サンプル]{
//}

//footnote[atom-tips][Mac OS Xの場合、Command+Shift+Pでコマンドパレットが開くのでgrammarなどそれっぽいワードを投げ込むとマウスなしで操作できます]
//footnote[atom-images-disclaimer][プラグインの導入状態やAtomのバージョンによって、画像どおりの見た目じゃない場合のほうが多いはずです]

=={install_review} Re:VIEWをインストールする

#@# NOTE author:vvakame

次に、Ruby版Re:VIEWをインストールします。
PDFやepubの生成などの最終出力を行うのに必要なので、重要です。

RubyとRubyGemsはすでに利用可能な環境になっているものとします。
インストールは単に次のコマンドを実行するだけです@<fn>{experimental-review}。Rubyのインストール方法次第ではsudoが必要かもしれません。

//cmd{
$ gem install review
//}

これだけです。
詳しい使い方は@<chapref>{review-introduction}で解説します。

とりあえず試してみたい場合、次のコマンドを実行してください。

//cmd{
$ review-init sample
$ cd sample

# もしrakeコマンドがまだ入っていなかったら（sudoが必要な場合もある）
$ gem install rake

# 各種ビルド HTML & PDF & EPUB
$ rake html_all
$ rake clean pdf
$ rake clean epub
//}

このコマンドではHTML、PDF、EPUB形式でサンプルを出力しています。

//footnote[experimental-review][review-pegという実験的パッケージがありますが熱心なRe:VIEW信者でない限り通常のreviewを使えばよいでしょう]

===[column] Ruby導入の手引き Mac OS X、Linux編

Macの場合、何もしなくてもデフォルトでRubyが導入されています。
この状態だとgem installを実行するときにsudoが必要になります。
またデフォルトのRubyのバージョンは若干古いため、最新のものを入れたほうがよいでしょう。
システムのデフォルトのままだと、破壊的（かもしれない）操作をするのが怖いですし、イザという時にリセットすることもやりにくいです。
万一のときに@<code>{rm -rf ~/.rbenv}すればよい環境を作ると精神的安らぎが得られます。

そのため本書ではrbenvの利用をお勧めします。
rbenvのインストール自体は公式サイト@<fn>{rbenv}に譲ります。
rbenvインストール後の手順は次のとおりです。

//cmd{
$ rbenv install --list
# 最新のを適当に入れれば良い 執筆時点では 2.2.3
$ rbenv install 2.2.3
# グローバルなrubyコマンドのバージョンを設定する localも存在する
$ rbenv global 2.2.3
# reviewをインストール
$ gem install review
# そのままではreview-compileにパスが通ってない状態なのでrehashする
$ rbenv rehash
//}

===[/column]

//footnote[rbenv][@<href>{https://github.com/sstephenson/rbenv#installation}]

===[column] Ruby導入の手引き Windows編

RubyInstaller@<fn>{rubyinstaller}を使うとよいでしょう。
しかし、TechBoosterではWindows環境下ではロクなLaTeX環境を構築できていないので素直に仮想環境を利用しています。
PDFを生成する必要がなければ、試す価値があるでしょう。

===[/column]

//footnote[rubyinstaller][@<href>{http://rubyinstaller.org/}]

== PDF出力を準備する

#@# NOTE author:vvakame

PDF出力の準備をします。
Re:VIEW文書をPDFに変換するにはLaTeX（platexまたはlualatexなど）を使います。
出力時の処理はreview形式→reviewツール実行→latex形式→platex実行→PDF という流れです。

==== Mac OS Xの場合

MacTeX@<fn>{mactex}を使いましょう。執筆時点ではMacTeX 2015が最新バージョンです。

//footnote[mactex][@<href>{https://www.tug.org/mactex/}]

==== Linuxの場合

texliveパッケージを利用します。
Ubuntu、Debianともに次のコマンドで導入できます。

//emlist{
$ sudo apt-get install texlive-lang-cjk texlive-fonts-recommended
//}

==== Windowsの場合

LaTeX環境の構築の難易度が高いため、Dockerなどの仮想環境を使うとよいでしょう。

==[column] Dockerとは？

Dockerは最近はやりの仮想環境用のツールです。
Linuxカーネルに組み込みの機能を使って、軽量かつ無駄の少ない仮想化環境を実現しています。
そのため、Mac OS XやWindowsでは直接は利用できません。
しかし、そのためのdocker-machineという仕組みが用意されています。

docker-machineはデフォルトではVirtualBoxを利用して、Linux環境を立ち上げその中でDocker用仮想環境を作成します。
このツールを使うと、Mac OS XやWindows環境でもDockerを利用することができます。

Dockerはざっくり次の使い方をします。

 1. Dockerfileを書く。Dockerfileはイメージの設計図で、主にコマンドの羅列である。
 2. 他人が書いたDockerfileを元に、Docker, Incがtrusted buildを作成してくれる。
 3. 他人の作ったイメージを元に自分のDockerfileを書く。

本書ではDockerやdocker-machineのインストール方法や使い方は解説しません。
その時々で適切なやり方を調べてみてください。

==[/column]

//footnote[docker-machine][@<href>{https://docs.docker.com/machine/}]
//footnote[docker-hub][@<href>{https://hub.docker.com/}]

==[column] Dockerを使ってどこでもビルド

Ruby入れたりTeX入れたりめんどくさすぎる！
という人のために、Dockerのイメージを用意@<fn>{docker-review}してあります。

//cmd{
$ docker run -i -t vvakame/review -v $(pwd):/book /bin/bash
//}

コマンドを実行すると、reviewとlatexの実行環境が整った環境が直ちに使えます。
コマンド実行後のディレクトリは@<code>{/book}ディレクトリにマウントされます。
適宜コンパイル用のコマンドを実行してください。

#@# prh:disable
実用的な例を知りたい場合は、この本のリポジトリのbuild-in-docker.shを参照してください。
@<href>{https://github.com/TechBooster/C89-FirstStepReVIEW-v2/blob/master/build-in-docker.sh}

==[/column]

//footnote[docker-review][@<href>{https://hub.docker.com/r/vvakame/review/}]
