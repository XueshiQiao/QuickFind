#!/bin/sh

DOWNLOAD_URI=https://github.com/qiaoxueshi/QuickFind/releases/download/0.1.1/QuickFind.xcplugin.tar.gz
PLUGINS_DIR="${HOME}/Library/Application Support/Developer/Shared/Xcode/Plug-ins"

mkdir -p "${PLUGINS_DIR}"
curl -L $DOWNLOAD_URI | tar xvz -C "${PLUGINS_DIR}"

echo "QuickFind successfuly installed!!!🍻   Please restart your Xcode."

