# C89-FirstStepReVIEW-v2

## 本を読むには？

### 電子書籍として閲覧する場合

https://techbooster.booth.pm/
でPDF版の販売予定があります

## この本のビルドの仕方

rbenvやnodebrewを利用してRubyやNode.jsの準備をしている前提。
もしそうではない場合、適宜sudoを補うこと。
Node.jsは4.x系以上が必須です。

graphvizを使ったのでbrew install graphvizとかが必要かもしれません。

```
$ gem install bundler
$ git clone git@github.com:TechBooster/C89-FirstStepReVIEW-v2.git
$ cd C89-FirstStepReVIEW-v2
$ npm install
$ npm run pdf
```

その他細かい準備(tex入れたり)は[FirstStepReVIEW](https://github.com/TechBooster/FirstStepReVIEW)に準じる。

めんどくさい場合はRe:VIEWビルド用の[dockerイメージ](https://registry.hub.docker.com/u/vvakame/review/)を用意してあるので使ってください。
Dockerがうまく動くようになっている場合、以下のコマンドで細かい準備なしにビルドを行うことができる。

```
$ docker pull vvakame/review
$ ./build-in-docker.sh
```
