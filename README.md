# FirstStepReVIEW-v3

「技術書をかこう！〜はじめてのRe:VIEW〜第3版」はRe:VIEW 5.8に対応した執筆ノウハウ本です。
Re:VIEWの使い方と制作にあたっての企画〜執筆〜編集〜告知〜会場頒布までのノウハウをギュッと詰めています。

本リポジトリやTechBoosterが利用してる書籍のレイアウト（B5/A5/電子書籍）は[ReVIEW-Templateリポジトリ](https://github.com/TechBooster/ReVIEW-Template)で公開しています。

## 本を読むには？

### 電子書籍として閲覧する場合

 * https://techbooster.booth.pm/

ここでPDF版を販売しています。

### 物理本がほしい場合

技術書典15で販売を予定しています。

## この本のビルドの仕方
CloneしてGitHub Actions経由で出力するのが、たぶん一番楽です。

こまかなビルド環境の準備は[Setup方法](https://github.com/TechBooster/FirstStepReVIEW-v3/blob/main/articles/setup.re)に準じます。
Dockerコンテナでビルドする場合、ローカルでの環境は最低限で大丈夫です。

### Dockerを使ってPDF出力する

TeXの環境構築が困難な場合、一式セットアップ済みの[dockerイメージ](https://registry.hub.docker.com/u/vvakame/review/)を用意してあるので使ってください。
Dockerがうまく動くようになっている場合、以下のコマンドで細かい準備なしにビルドを行うことができます。

```
$ docker pull vvakame/review:5.8
$ ./build-in-docker.sh
```

### ローカル環境でPDF出力する

rbenvやnodebrewを利用してRubyやNode.jsの準備をしている前提です。
もしそうではない場合、適宜sudoを補うこと。

```
$ gem install bundler
$ git clone https://github.com/TechBooster/FirstStepReVIEW-v3.git
$ cd FirstStepReVIEW-v3
$ npm install
$ npm run pdf
```
## 権利

 * 文章、イラストデータについては著作物の権利を権利者に留保します
   * 権利者はGitHubの利用規約に基づき、リポジトリのForkに同意しています
   * 文章、イラストデータの流用、改変は許可していません（利用したい場合はIssue等でお問い合わせください）
 * 設定ファイル、テンプレートなど制作環境（techbooster-doujin-base.styなど）はMITライセンスです
   * 再配布などMITライセンスで定める範囲で権利者表記をおねがいします
   * 本設定を使って生成した書籍は現段階のRe:VIEWではソフトウェアたりえません。したがってライセンスは発生しません（あとがきなどへの表記はあると嬉しいものの生成物での表記は不要です）
