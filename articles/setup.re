={setup} Re:VIEWでの執筆環境を整える
#@# NOTE author:mhidaka

本章ではRe:VIEWで執筆するための環境を整えます。
TechBoosterの著者陣は、もれなく全員がRe:VIEW記法で執筆するスタイルです。
慣れないうちはエラーに遭遇したり、やり方に迷ったりしているので、CI/CD環境があってこそ運用できているといえます。

Re:VIEW記法は、馴染みがないものなので覚えるのはちょっと面倒ですね。書籍作りを支えるものなので表現したい内容を優先し、手を動かしながら学びノウハウを貯めてください。

2023年11月現在では、Microsoftが開発提供するエディタVisual Studio Codeと@<kw>{Extensions,拡張機能}のvscode-language-reviewを利用することが一般的です。

 * @<href>{https://code.visualstudio.com/}
 * @<href>{https://github.com/atsushieno/vscode-language-review}

いきなりRe:VIEWで書き始めるのはハードルが高いなと感じた場合はMarkdownで書いたあとにRe:VIEWファイルに変換する手法をおすすめします。
しかしMarkdownで執筆する場合は、図表の細やかな調整やリストへの参照など本らしい表現に対応するMarkdown記法がありません。
慣れるにしたがってRe:VIEWファイル上で、最終調整することも多くなるのでRe:VIEWファイルでの執筆・編集を前提にセットアップ手順を知っておきましょう。

本書執筆時点での検証済みのバージョンは次のとおりです。

#@# TODO 入稿前にここのバージョンを再確認すること

 * Visual Studio Code October 2023 (version 1.84)
 * vscode-language-review v0.7.4
 * Re:VIEW 5.8.0

== Visual Studio CodeとExtensionsのセットアップ

Visual Studio Codeをダウンロードしてインストールします。Visual Studio Codeを起動し、Extensionsを表示します。
メニューから@<tt>{基本設定 > Extensions}または@<tt>{表示 > Extensions}どちらからで表示できます。

サイドバーの上部にマーケットの検索ウインドウがあるので検索ワード「Language Review」と入力してvscode-language-reviewを探してください（@<img>{vscode_extensions}）。

//image[vscode_extensions][vscode-language-reviewをインストールする]{
//}

画面のインストールボタンを押せば完了です。
vscode-language-reviewは、Visual Studio Code上で、Re:VIEW記法を使いやすくする便利な拡張機能を提供します。

 * Liveプレビュー
 * シンタックスハイライト
 * アウトライン表示とコードジャンプ
 * Re:VIEW記法のチェックと警告、参照先入力支援
 * 文章の校正支援

@<img>{vscode-language-review-sample1}はRe:VIEW記法でかかれた@<tt>{.re}ファイルを
開いたものです。見出しや箇条書き、ハイパーリンクなどRe:VIEW記法部分をシンタックスハイライト機能でわかりやすく表示します。

//image[vscode-language-review-sample1][シンタックスハイライト機能]{
//}

Visual Studio Codeの画面右上部の@<tt>{Show preview}ボタンがあります。
Show preview（@<img>{vscode-language-review-sample2}）はRe:VIEWでのシンタックスがどのように働いているかをプレビューできます。

//image[vscode-language-review-sample2][便利なプレビュー機能]{
//}

正確にはHTMLでのプレビューですので実際の紙面とはレイアウトが違います@<fn>{scale-note}。
Re:VIEW記法のミスがないかの確認用と考えてください。

//footnote[scale-note][差分は文章の折り返し位置がわかりやすいです。そのほかの例としてはRe:VIEWにはimageという画像表示のためのブロック命令がありますが、オプションパラメータ@<code>{scale}のサイズ指定は最終出力のフォーマットや判型で見栄が異なります]

TechBoosterではVisul Studio Codeとvscode-language-review拡張機能で執筆し、
LiveプレビューでエラーチェックしてGitHubのリポジトリにpush、CIでPDFを確認するというワークフローを運用しています。

=={install_review} Re:VIEW image for Dockerのセットアップ

Docker上でRe:VIEWを動かすための手順を解説します。Dockerはコンテナ型仮想化技術のプラットフォームです。
Re:VIEW image for Dockerは最新のRe:VIEWをどの環境でも安定して使えるコンテナイメージで、vvakameが公開とメンテナンスをしています。

本書執筆時点での検証済みのバージョンは次のとおりです。

#@# TODO 入稿前にここのバージョンを再確認すること

 * macOS Sonoma
 * Docker Desktop Version 4.25.0 (126437)

Re:VIEWツールそのものはRuby言語で書かれており、macOS、Windows、LinuxどのOSでも動作します。
ただしRubyのバージョンやPDFを出力するLaTeXを構築する手順はプラットフォームごとに微妙に異なるので、
Re:VIEWの環境構築でトラブルに遭遇した場合に解決は困難を極めます。

Re:VIEWの環境を仮想化できたことで現在は多くの書籍がRe:VIEW image for Dockerを使って作られています。

導入には、まずDocker Desktopを次のURLからダウンロードしてインストールします。

 * @<href>{https://www.docker.com/}

Windowsでの手順は次のURLで詳しく触れられています。

 * @<href>{https://github.com/vvakame/docker-review/blob/master/doc/windows-review.md}

2023年11月現在、Docker Desktopのライセンスは有償と無償どちらも存在しています。無償のパーソナルプランから試してみてください。パーソナルプランでは個人開発者の利用、教育目的、非商用のオープンソースプロジェクトでの利用を想定しており、これらに加えてFAQには小規模なビジネス向け（従業員 250名未満、かつ収益 1 千万ドル未満）に対しても無償提供を継続すると記載@<fn>{docker-faq}があります。

//footnote[docker-faq][@<href>{https://matsuand.github.io/docs.docker.jp.onthefly/desktop/faqs/#do-i-need-to-pay-to-use-docker-desktop}]

Dockerのインストールが完了したあとはRe:VIEW image for Dockerをダウンロードします。コマンドラインに次のとおり入力してください。

//cmd{
docker pull vvakame/review:5.8
//}

コマンドではタグに@<code>{5.8}を指定しています。Re:VIEW image for DockerでサポートしているRe:VIEWは5.3〜5.8です。

===[column] 取得済みイメージの確認方法

次のコマンドでpullしているDockerイメージを確認できます。

//cmd{
docker images vvakame/review  
//}

本書の手順を実行したあとでは@<tt>{vvakame/review}リポジトリのタグ@<code>{5.8}を確認できます。

//cmd{
REPOSITORY       TAG       IMAGE ID       CREATED        SIZE
vvakame/review   5.8       5cb030602a81   4 months ago   3.28GB
//}

書籍制作環境を全部含んでいるのでイメージサイズが3GB超と大きめです。
Dockerイメージは次のリポジトリで公開しています。インストールされているコマンドや初期設定を確認したい場合にアクセスしてください。

  * @<href>{https://github.com/vvakame/docker-review}


===[/column]

== PDFファイルを出力する

Docker経由でのPDF出力を試しましょう。
前節で少し触れましたがRe:VIEWでPDFに変換するにはLaTeX（platexまたはlualatexなど）を使います。

Re:VIEW image for Docker内部のワークフローは@<tt>{.re}ファイルを含んだプロジェクトからRe:VIEWツールを実行し、出力対象がPDFファイルであればLaTeX形式に変換、TeXLiveを実行して生成したPDFファイルをローカルマシンにコピーして完了という流れです。

TechBoosterが提供しているReVIEW-templateリポジトリをベースに執筆している場合のPDF出力から説明します。

 * @<href>{https://github.com/TechBooster/ReVIEW-Template}

Dockerで出力するスクリプトは@<tt>{C89-FirstStepReVIEW-v2}などプロジェクトルートから実行します（直下に@<tt>{articles}ディレクトリがあることを確認してください）。

//cmd{
yourbook_dir % pwd
/Users/mhidaka/repos/C89-FirstStepReVIEW-v2

yourbook_dir % ./build-in-docker.sh
//}

//cmd{
yourbook_dir/articles/bookname.pdf
//}

PDFファイルは@<tt>{articles/}ディレクトリの下に@<tt>{書籍名.pdf}という名前で出力されます。


#@# prh:disable
スクリプトファイルのなかでRe:VIEWの設定ファイル@<tt>{articles/config.yml}を指定しています。書籍ごとに変えたいなど中身を知りたい場合は、この本のリポジトリにある@<tt>{build-in-docker.sh}を参照してください。

#@# prh:disable
 *  @<href>{https://github.com/TechBooster/C89-FirstStepReVIEW-v2/blob/master/build-in-docker.sh}

スクリプトを使わず@<code>{docker}コマンドを手で打ち込んで実行する場合は次のコマンドです。

//cmd{
docker run -t --rm -v `pwd`:/book vvakame/review:5.8 /bin/bash -ci 
         "cd /book && ./setup.sh && REVIEW_CONFIG_FILE=config.yml npm run pdf"
//}

毎回コマンドを打ち込むのは大変なので@<tt>{build-in-docker.sh}のようにまとめておくといいでしょう。

===[column] Re:VIEW image for Dockerのすごさ

本節で説明したワークフローでは、わかりやすさのためにRe:VIEWツールの内部で行なっている処理も含んでいます。

Re:VIEW image for DockerにはMeCabといった日本語形態素解析システムも入っているので、Re:VIEWで索引を作るといった真の書籍っぽい機能を引き出せます。索引がついた同人誌はあまり見かけませんが商業利用も盛んなRe:VIEWならではです。

利用可能なフォントも豊富で、デフォルトでは原ノ味フォントを使います。オプションでIPAフォント、Notoフォントを導入可能です。いずれもフォント埋め込み済みのPDFファイルを出力できるので入稿でも安心です。

原ノ味フォントは明朝体、ゴシック体ともにマルチウェイトなのでRegular、Medium、Boldといった太さも7種類に対応していて利用実績が多く、読み慣れています。

IPAフォントは明朝体、ゴシック体それぞれに等幅とプロポーショナルがあるオープンソースのフォントです。
ウェイトに対応していないため、太字にしたい場合にはシステム側で後処理が必要です。

NotoフォントはGoogleによって開発されたオープンソースフォントです。明朝体、ゴシック体の日本語フォント以外にも数多くのNotoフォントファミリーから構成されており、馴染みのある欧文フォントであるRobotoとの相性も抜群です。

Re:VIEW image for Docker登場以前はフォントのセットアップだけでも一苦労で文字化けや意図しない表示に悩まされることも多かったものです。Re:VIEWの作者とコンテナのメンテナを褒め称えましょう。

===[/column]


== 応用編：書籍をローカル環境でビルドするには

本節ではRe:VIEWファイルをローカル環境でコンパイルする方法を紹介します。Re:VIEWは、Markdown、プレーンテキスト、HTMLやEPUBなど多様なフォーマットに対応しています。
ローカル環境の構築ドキュメントとPDFを出力する@<code>{review-pdfmaker}、EPUBを出力する@<code>{review-epubmaker}、Webページを出力する@<code>{review-webmaker}に触れますが
入稿に利用する形式は@<code>{review-pdfmaker}コマンドでのPDF形式です。

わたしたちはDocker経由の利用を推奨していること、ローカル環境での構築でトラブルが起きると解決が大変なことの2点を鑑みて各OSでのインストール手順の解説を避ける構成を採っています。

しかしローカル環境があると色々な試行錯誤、とくにレイアウト調整やデバッグなどに便利ですので試したい読者のためにポインタを示します。
TechBoosterでは編集者は手元の環境でPDFファイルを確認しています。これはページ数の調整や記法の修正、図表の見栄で頻繁なPDF再出力を行うためです。

=== ローカル環境の構築

Re:VIEWを使うにはRubyのインストールおよびTeXLive 2023を導入してください。PDF出力を目的としない場合はTeXLive 2023は不要です。OSごとのインストール手順はそれぞれのドキュメントを参照して実施してください。

 * @<href>{https://github.com/kmuto/review/blob/master/doc/quickstart.ja.md}
 * @<href>{https://texwiki.texjp.org/?TeX%20Live}

Re:VIEWのインストールは次のとおりRubyGemsを使うのがいいでしょう。

//cmd{
gem install review
//}

Re:VIEWの開発チームは、定期的に新しいバージョンをリリースしています。
執筆中、または執筆を完了した書籍のアップデートなどでバージョンを変更する場合はチェンジログを確認し、意図せずレイアウトが崩れないよう互換性確保に気をつけてください。

=== review-pdfmaker

@<code>{review-pdfmaker}はそのプロジェクトのPDFファイルを生成します。
引数としてYAMLファイル（@<tt>{config.yml}）をひとつ指定します。

//cmd{
> review-pdfmaker config.yml
(出力省略)
//}

YAMLファイルには本のタイトルや筆者名といった本のメタデータとなる設定を記述しておきます。
その設定のひとつ@<code>{bookname}が出力ファイル名に対応しています。

@<code>{bookname}が「book」となっている場合、生成した@<tt>{book.pdf}を自身のディレクトリに保存します。

@<code>{review-pdfmaker}の内部では別のコマンド@<code>{review-compile --target=latex}を実行しています。
そのあとに@<code>{platex}や@<code>{dvipdfmx}のようなTeX形式のファイルからPDFへ変換するRe:VIEW以外の外部コマンドを実行します。

=== 制作時に出会うエラーたち

@<code>{review-pdfmaker}をはじめて使うときは作法がわからず戸惑うかもしれません。
もっとも単純な事例では@<tt>{catalog.yml}の@<code>{CHAPS}で追加した@<tt>{.re}ファイルを書き忘れることです。
単純に参照がない場合もビルドが成功するので（機械にはわからないエラーなので）追加分が見えないため慣れないうちは困惑します。

検出しにくい見た目の問題も挙げましょう。

 * 本文中にリスト掲載したソースコードが長すぎて紙面をはみ出している
 * 箇条書きで書いた「@<code>{*}」の先頭に付与すべき半角スペースを忘れていて本文に直接@<code>{*}が表示されている
 * 表に複数行のテキストを入れたら折返しがうまくいかず不格好になる

装飾やレイアウトの問題についてはビルドエラーとはなりません。意図したレイアウトでPDFが出力されているかは作成者によるケアが必要です。

なおRe:VIEW記法を間違えたときは構文エラーが起きます。エラーが発生すると標準出力に発生時点のログが残るのでとりあえず眺めることになるでしょう。

前述のとおり、TeXの出力ログやエラーも含まれているので大量のログが急にでて驚くかもしれませんね。
エラーログから間違えた場所を探すのは苦労するので、たくさん書いてからRe:VIEW記法に書き直せばいいやというスタンスより、ちょっとずつ取り込んでおくほうが安心です。
テンプレートリポジトリのCIはそのために存在しています。

=== review-epubmaker

@<code>{review-epubmaker}はプロジェクトのメタデータとなるYAMLファイルを引数としてEPUBファイルを生成します。
EPUBファイルの実態はHTMLファイルやCSSファイルをZIPでアーカイブ化したものです。

Re:VIEWはEPUBの生成処理で、システムにインストールされているZIPコマンドを使用します。
事前にZIPコマンドをインストールしておいてください。

//cmd{
> review-epubmaker config.yml
(出力省略)
> file book.epub
book.epub: EPUB ebook data
（電子書籍リーダに読み込ませることで内容を確認出来る）
//}

YAMLファイル内の@<code>{bookname}を元にして出力ファイル名を決定します。

#@# prh:disable
=== review-webmaker

#@# prh:disable
@<code>{review-webmaker}はプロジェクトのメタデータとなるYAMLファイルを引数としてWebサイト用ファイルを生成します。
HTMLファイルやCSSファイル、画像を@<tt>{webroot}ディレクトリに出力します。

//cmd{
> review-webmaker config.yml
(出力省略)
> file webroot
webroot: directory
//}

読み込むCSSファイルなどは参照するYAMLファイル内の@<code>{webmaker}パラメータを元にして設定しています（@<img>{webroot}）。

#@# prh:disable
//image[webroot][review-webmakerの出力例][scale=0.75]{
//}
