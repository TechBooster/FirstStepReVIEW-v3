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

TODO WindowsとかLinuxでの調査

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

//footnote[atom-tips][Mac OS Xの場合、Command+Shift+Pでコマンドパレットが開くのでgrammarなどそれっぽいワードを投げ込むとマウスなしで操作できます。]
//footnote[atom-images-disclaimer][プラグインの導入状態やAtomのバージョンによって、画像どおりの見た目じゃない場合のほうが多いはずです。]

== Re:VIEWのインストール

TODO vvakame

== PDF出力の準備

TODO vvakame

== Dockerを使ってどこでもビルド

TODO vvakame

== 推奨するディレクトリ構成

TODO vvakame

== トラブルシューティング

TODO mhidaka
