# C89-FirstStepReVIEW-v2

## 本を読むには？

### 電子書籍として閲覧する場合

https://griflet.net/github/TechBooster/C89-FirstStepReVIEW-v2/

Twitterログインが必要です。
見られないときは @amedama か @mhidaka か @vvakame にお伝え下さい。

## この本のビルドの仕方

```
$ npm install -g grunt-cli
$ gem install bundler
$ git clone git@github.com:TechBooster/C89-FirstStepReVIEW-v2.git
$ cd C89-FirstStepReVIEW-v2
$ npm install
$ npm run pdf
```

その他細かい準備(tex入れたり)は[FirstStepReVIEW](https://github.com/TechBooster/FirstStepReVIEW)に準じる。
めんどくさい場合はRe:VIEWビルド用の[dockerイメージ](https://registry.hub.docker.com/u/vvakame/review/)を用意してあるので使ってください。
