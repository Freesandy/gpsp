#ifndef LIBRETRO_CORE_OPTIONS_H__
#define LIBRETRO_CORE_OPTIONS_H__

#include <stdlib.h>
#include <string.h>

#include "libretro.h"
#include "retro_inline.h"

#ifndef HAVE_NO_LANGEXTRA
#include "libretro_core_options_intl.h"
#endif

/*
 ********************************
 * VERSION: 1.3
 ********************************
 *
 * - 1.3: Move translations to libretro_core_options_intl.h
 *        - libretro_core_options_intl.h includes BOM and utf-8
 *          fix for MSVC 2010-2013
 *        - Added HAVE_NO_LANGEXTRA flag to disable translations
 *          on platforms/compilers without BOM support
 * - 1.2: Use core options v1 interface when
 *        RETRO_ENVIRONMENT_GET_CORE_OPTIONS_VERSION is >= 1
 *        (previously required RETRO_ENVIRONMENT_GET_CORE_OPTIONS_VERSION == 1)
 * - 1.1: Support generation of core options v0 retro_core_option_value
 *        arrays containing options with a single value
 * - 1.0: First commit
*/

#ifdef __cplusplus
extern "C" {
#endif

/*
 ********************************
 * Core Option Definitions
 ********************************
*/

/* RETRO_LANGUAGE_ENGLISH */

/* Default language:
 * - All other languages must include the same keys and values
 * - Will be used as a fallback in the event that frontend language
 *   is not available
 * - Will be used as a fallback for any missing entries in
 *   frontend language definition */

struct retro_core_option_definition option_defs_us[] = {
   {
      "mgba_solar_sensor_level",
      "光线传感器级别",
      "设置环境光强度. \n"
      "可以在卡带上有光线传感器的游戏上使用, 例如《我们的太阳》系列. ",
      {
         { "0",  NULL },
         { "1",  NULL },
         { "2",  NULL },
         { "3",  NULL },
         { "4",  NULL },
         { "5",  NULL },
         { "6",  NULL },
         { "7",  NULL },
         { "8",  NULL },
         { "9",  NULL },
         { "10", NULL },
         { NULL, NULL },
      },
      "0"
   },
   {
      "mgba_allow_opposing_directions",
      "允许相反方向输入",
      "允许同时按下/快速切换/同时按住左右或者上下方向键, 这可能会引起移动方面的问题. ",
      {
         { "no",  "disabled" },
         { "yes", "enabled" },
         { NULL, NULL },
      },
      "no"
   },
   {
      "mgba_gb_model",
      "Game Boy型号 (须重启)",
      "使用指定的Game Boy型号运行游戏. \n"
      "'自动检测'会为当前游戏选择最适合的型号. ",
      {
         { "Autodetect",       "自动检测" },
         { "Game Boy",         NULL },
         { "Super Game Boy",   NULL },
         { "Game Boy Color",   NULL },
         { "Game Boy Advance", NULL },
         { NULL, NULL },
      },
      "Autodetect"
   },
   {
      "mgba_use_bios",
      "使用BIOS文件 (须重启)",
      "使用官方BIOS/引导程序, 如果在RetroArch系统目录下有的话. ",
      {
         { "ON",  "启用" },
         { "OFF", "禁用" },
         { NULL, NULL },
      },
      "ON"
   },
   {
      "mgba_skip_bios",
      "跳过BIOS启动画面 (须重启)",
      "使用官方BIOS/引导程序时, 跳过启动标题画面. \n"
      "'使用BIOS文件 (须重启)'禁用时, 此项忽略. ",
      {
         { "OFF", "禁用" },
         { "ON",  "启用" },
         { NULL, NULL },
      },
      "OFF"
   },
   {
      "mgba_sgb_borders",
      "使用Super Game Boy边框 (须重启)",
      "运行Super Game Boy增强游戏时, 显示Super Game Boy边框. ",
      {
         { "ON",  "启用" },
         { "OFF", "禁用" },
         { NULL, NULL },
      },
      "ON"
   },
   {
      "mgba_idle_optimization",
      "移除空循环",
      "缩短系统载入时间, 通过优化'空循环' - 这些代码不做任何事, 但是CPU全速运转 (类似汽车的空档运转). \n"
      "此项可以提升性能, 在低端设备上应该启用. ",
      {
         { "Remove Known",      "移除已知代码" },
         { "Detect and Remove", "检测并移除" },
         { "Don't Remove",      "不移除" },
         { NULL, NULL },
      },
      "Remove Known"
   },
   {
      "mgba_frameskip",
      "跳帧",
      "跳过一定帧数, 以改善性能, 代价是牺牲画面流畅度. '自动' 根据前台设置跳帧. '自动 (阈值)' 利用跳帧阈值(%)的设定跳帧. '固定间隔'利用跳帧间隔的设定跳帧.",
      {
         { "disabled",       NULL },
         { "auto",           "自动" },
         { "auto_threshold", "自动 (阈值)" },
         { "fixed_interval", "固定间隔" },
         { NULL, NULL },
      },
      "disabled"
   },
   {
      "mgba_frameskip_threshold",
      "跳帧阈值(%)",
      "当'跳帧'设置为自动(阈值)'时, 低于指定音频缓冲区占用阈值(百分比)时跳帧. 较高的值可降低音频破音的风险. ",
      {
         { "15", NULL },
         { "18", NULL },
         { "21", NULL },
         { "24", NULL },
         { "27", NULL },
         { "30", NULL },
         { "33", NULL },
         { "36", NULL },
         { "39", NULL },
         { "42", NULL },
         { "45", NULL },
         { "48", NULL },
         { "51", NULL },
         { "54", NULL },
         { "57", NULL },
         { "60", NULL },
         { NULL, NULL },
      },
      "33"
   },
   {
      "mgba_frameskip_interval",
      "跳帧间隔",
      "跳过一定帧数, 以改善性能, 代价是牺牲画面流畅度. \n"
      "这里设置的值是每渲染一帧后跳过的帧数 - 即'0' = 60fps, '1' = 30fps, '2' = 20fps, 以此类推. ",
      {
         { "0",  NULL },
         { "1",  NULL },
         { "2",  NULL },
         { "3",  NULL },
         { "4",  NULL },
         { "5",  NULL },
         { "6",  NULL },
         { "7",  NULL },
         { "8",  NULL },
         { "9",  NULL },
         { "10", NULL },
         { NULL, NULL },
      },
      "0"
   },
#if defined(COLOR_16_BIT) && defined(COLOR_5_6_5)
   {
      "mgba_color_correction",
      "色彩校正",
      "调整输出色彩以匹配真实GBA/GBC的显示效果. ",
      {
         { "OFF",  "禁用" },
         { "GBA",  "Game Boy Advance" },
         { "GBC",  "Game Boy Color" },
         { "Auto", "自动" },
         { NULL, NULL },
      },
      "OFF"
   },
   {
      "mgba_interframe_blending",
      "帧间混合",
      "模拟LCD屏幕鬼影效果. \n"
      "'简单'以50:50比例混合当前帧和上一帧. '只能'尝试检测屏幕闪烁, 只对受影响的像素进行50:50混合. \n"
      "'LCD鬼影'通过混合多个缓冲帧来模拟原生LCD响应时间. \n"
      "'简单'或'智能'是某些运行游戏必需的, 这些游戏通过主动激发LCD鬼影来实现透明特效 (Wave Race, Chikyuu Kaihou Gun ZAS, F-Zero, the Boktai series...)",
      {
         { "OFF",               "禁用" },
         { "mix",               "简单 (精确)" },
         { "mix_fast",          "简单 (快速)" },
         { "mix_smart",         "智能 (精确)" },
         { "mix_smart_fast",    "智能 (快速)" },
         { "lcd_ghosting",      "LCD鬼影 (精确)" },
         { "lcd_ghosting_fast", "LCD鬼影 (快速)" },
         { NULL, NULL },
      },
      "OFF"
   },
#endif
	{
      "mgba_force_gbp",
      "开启GBP震动 (需重启)",
      "启用此功能将允许带有Game Boy Player启动标志的兼容游戏震动.  由于任天堂决定此功能应该起作用的方式, 因此在某些游戏中可能会引起故障, 例如闪烁或延迟. ",
      {
         { "OFF", "禁用" },
         { "ON",  "启用" },
         { NULL, NULL },
      },
      "OFF"
   },
   { NULL, NULL, NULL, {{0}}, NULL },
};

/*
 ********************************
 * Language Mapping
 ********************************
*/

#ifndef HAVE_NO_LANGEXTRA
struct retro_core_option_definition *option_defs_intl[RETRO_LANGUAGE_LAST] = {
   option_defs_us, /* RETRO_LANGUAGE_ENGLISH */
   NULL,           /* RETRO_LANGUAGE_JAPANESE */
   NULL,           /* RETRO_LANGUAGE_FRENCH */
   NULL,           /* RETRO_LANGUAGE_SPANISH */
   NULL,           /* RETRO_LANGUAGE_GERMAN */
   option_defs_it, /* RETRO_LANGUAGE_ITALIAN */
   NULL,           /* RETRO_LANGUAGE_DUTCH */
   NULL,           /* RETRO_LANGUAGE_PORTUGUESE_BRAZIL */
   NULL,           /* RETRO_LANGUAGE_PORTUGUESE_PORTUGAL */
   NULL,           /* RETRO_LANGUAGE_RUSSIAN */
   NULL,           /* RETRO_LANGUAGE_KOREAN */
   NULL,           /* RETRO_LANGUAGE_CHINESE_TRADITIONAL */
   NULL,           /* RETRO_LANGUAGE_CHINESE_SIMPLIFIED */
   NULL,           /* RETRO_LANGUAGE_ESPERANTO */
   NULL,           /* RETRO_LANGUAGE_POLISH */
   NULL,           /* RETRO_LANGUAGE_VIETNAMESE */
   NULL,           /* RETRO_LANGUAGE_ARABIC */
   NULL,           /* RETRO_LANGUAGE_GREEK */
   option_defs_tr, /* RETRO_LANGUAGE_TURKISH */
};
#endif

/*
 ********************************
 * Functions
 ********************************
*/

/* Handles configuration/setting of core options.
 * Should be called as early as possible - ideally inside
 * retro_set_environment(), and no later than retro_load_game()
 * > We place the function body in the header to avoid the
 *   necessity of adding more .c files (i.e. want this to
 *   be as painless as possible for core devs)
 */

static INLINE void libretro_set_core_options(retro_environment_t environ_cb)
{
   unsigned version = 0;

   if (!environ_cb)
      return;

   if (environ_cb(RETRO_ENVIRONMENT_GET_CORE_OPTIONS_VERSION, &version) && (version >= 1))
   {
#ifndef HAVE_NO_LANGEXTRA
      struct retro_core_options_intl core_options_intl;
      unsigned language = 0;

      core_options_intl.us    = option_defs_us;
      core_options_intl.local = NULL;

      if (environ_cb(RETRO_ENVIRONMENT_GET_LANGUAGE, &language) &&
          (language < RETRO_LANGUAGE_LAST) && (language != RETRO_LANGUAGE_ENGLISH))
         core_options_intl.local = option_defs_intl[language];

      environ_cb(RETRO_ENVIRONMENT_SET_CORE_OPTIONS_INTL, &core_options_intl);
#else
      environ_cb(RETRO_ENVIRONMENT_SET_CORE_OPTIONS, &option_defs_us);
#endif
   }
   else
   {
      size_t i;
      size_t num_options               = 0;
      struct retro_variable *variables = NULL;
      char **values_buf                = NULL;

      /* Determine number of options */
      while (true)
      {
         if (option_defs_us[num_options].key)
            num_options++;
         else
            break;
      }

      /* Allocate arrays */
      variables  = (struct retro_variable *)calloc(num_options + 1, sizeof(struct retro_variable));
      values_buf = (char **)calloc(num_options, sizeof(char *));

      if (!variables || !values_buf)
         goto error;

      /* Copy parameters from option_defs_us array */
      for (i = 0; i < num_options; i++)
      {
         const char *key                        = option_defs_us[i].key;
         const char *desc                       = option_defs_us[i].desc;
         const char *default_value              = option_defs_us[i].default_value;
         struct retro_core_option_value *values = option_defs_us[i].values;
         size_t buf_len                         = 3;
         size_t default_index                   = 0;

         values_buf[i] = NULL;

         if (desc)
         {
            size_t num_values = 0;

            /* Determine number of values */
            while (true)
            {
               if (values[num_values].value)
               {
                  /* Check if this is the default value */
                  if (default_value)
                     if (strcmp(values[num_values].value, default_value) == 0)
                        default_index = num_values;

                  buf_len += strlen(values[num_values].value);
                  num_values++;
               }
               else
                  break;
            }

            /* Build values string */
            if (num_values > 0)
            {
               size_t j;

               buf_len += num_values - 1;
               buf_len += strlen(desc);

               values_buf[i] = (char *)calloc(buf_len, sizeof(char));
               if (!values_buf[i])
                  goto error;

               strcpy(values_buf[i], desc);
               strcat(values_buf[i], "; ");

               /* Default value goes first */
               strcat(values_buf[i], values[default_index].value);

               /* Add remaining values */
               for (j = 0; j < num_values; j++)
               {
                  if (j != default_index)
                  {
                     strcat(values_buf[i], "|");
                     strcat(values_buf[i], values[j].value);
                  }
               }
            }
         }

         variables[i].key   = key;
         variables[i].value = values_buf[i];
      }

      /* Set variables */
      environ_cb(RETRO_ENVIRONMENT_SET_VARIABLES, variables);

error:

      /* Clean up */
      if (values_buf)
      {
         for (i = 0; i < num_options; i++)
         {
            if (values_buf[i])
            {
               free(values_buf[i]);
               values_buf[i] = NULL;
            }
         }

         free(values_buf);
         values_buf = NULL;
      }

      if (variables)
      {
         free(variables);
         variables = NULL;
      }
   }
}

#ifdef __cplusplus
}
#endif

#endif
