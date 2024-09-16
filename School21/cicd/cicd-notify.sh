#!/bin/bash

TIME=10
TELEGRAM_BOT_TOKEN="7006787655:AAGoEyzXbX-nxU_IMyvwmgKyRAM-Lebgr5Q"
TELEGRAM_USER_ID="614599494"

URL="https://api.telegram.org/bot$TELEGRAM_BOT_TOKEN/sendMessage"
TEXT="$CI_JOB_NAME status: $1%0A%0AProject:+$CI_PROJECT_NAME%0AURL:+$CI_PROJECT_URL/pipelines/$CI_PIPELINE_ID/%0ABranch:+$CI_COMMIT_REF_SLUG"

curl -s --max-time $TIME -d "chat_id=$TELEGRAM_USER_ID&disable_web_page_preview=1&text=$TEXT" $URL > /dev/null
