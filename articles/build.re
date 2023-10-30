={build} 書籍をビルドする

本章ではRe:VIEWファイルをコンパイルする方法を解説します。
PDFを出力する@<code>{review-pdfmaker}、EPUBを出力する@<code>{review-epubmaker}、Webページを出力する@<code>{review-webmaker}を順番に紹介します。

入稿に利用する形式は@<code>{review-pdfmaker}コマンドでのPDF形式ですがRe:VIEWは、Markdown、プレーンテキスト、HTMLやEPUBなど多様なフォーマットに対応しています。

== review-pdfmaker

@<code>{review-pdfmaker}はそのプロジェクトのPDFを生成します。
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

 * 本文中にリストとして掲載したソースコードが長すぎて紙面をはみ出している場合
 * 箇条書きのつもりで書いた「@<code>{*}」が半角スペースを忘れていて直接本文に表示されている場合
 * 表に複数行のテキストを入れたら折返しがうまくいかず不格好になる場合

装飾やレイアウトの問題についてはビルドエラーとはなりません。意図したレイアウトでPDFが出力されているかは作成者によるケアが必要です。

最後にRe:VIEW記法を間違えたときは構文エラーが起きます。エラーが発生すると標準出力に発生時点のログが残るのでとりあえず眺めることになるでしょう。
前述の説明のとおり、TeXの出力ログやエラーも含まれているので急に大量のログがでるので驚くことになります。
エラーログから間違えた場所を探すのは苦労するので、沢山書いてからRe:VIEW記法に書き直せばいいやというスタンスより、ちょっとずつ取り込んでおくほうが安心です。
テンプレートリポジトリのCIはそのために存在しています。

== review-epubmaker

@<code>{review-pdfmaker}同様、@<code>{review-epubmaker}はプロジェクトのメタデータとなるYAMLファイルを引数としてEPUBファイルを生成します。
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
== review-webmaker

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
