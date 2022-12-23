# SKSE Plugin helpers

![SKSE Plugin](Images/Plugin_Logo.png)

- [SKSE Plugin helpers](#skse-plugin-helpers)
- [`#include <SkyrimScripting/Plugin.h>`](#include-skyrimscriptingpluginh)
  - [`logger`](#logger)
    - [Customizing Log File Path](#customizing-log-file-path)
  - [`ConsoleLog`](#consolelog)
  - [SKSE Events (`OnInit { ... }`)](#skse-events-oninit---)
    - [Providing your own `SKSEPluginLoad`](#providing-your-own-sksepluginload)
  - [Game Events (`On<EventType>`)](#game-events-oneventtype)


# `#include <SkyrimScripting/Plugin.h>`

To get started, use the [Starter Kit](https://github.com/SkyrimScripting/SKSE_Template_StarterKit).

## `logger`

By default, a log file is created for your plugin, based on its plugin name.

`My Games\Skyrim Special Edition\SKSE\<your plugin name>.log`

To write to the log file, use:

- `logger::trace()`
- `logger::debug()`
- `logger::info()`
- `logger::warn()`
- `logger::error()`
- `logger::critical()`

You can pass `fmt` formatted strings:

```cpp
logger::info(
    "{}'s form ID in hexadecimal is {:x}",
    baseObject->GetName(),
    baseObject->GetFormID()
);
```

### Customizing Log File Path

If you want to customize the filename of the log _without_ changing the name of your SKSE mod:

```cpp
#include <SkyrimScripting/Plugin.h>

PluginLogFileName("Butts.log");

// Or customize the full system path:
PluginLogFullPath("C:\\logs\\butts.log");

// By default, we do NOT support logging to the Debug Console
// whenever a debugger is attached. To enable that feature:
PluginLogToDebugConsole;

// Or totally disable lots, entirely.
PluginLogDisable;

OnInit { ... }
```

## `ConsoleLog`

Want to log to the `~` game console?

```cpp
ConsoleLog("Hello, world!");
```

It supports `fmt` formatting, just like `logger`:

```cpp
ConsoleLog(
    "{}'s form ID in hexadecimal is {:x}",
    baseObject->GetName(),
    baseObject->GetFormID()
);
```

> **Note:** the console is not available for logging until `OnDataLoaded` or after.

## SKSE Events (`OnInit { ... }`)

Specify code that should run on certain SKSE event:

```cpp
#include <SkyrimScripting/Plugin.h>

OnInit {
    logger::info("I run immediately, as soon as the plugin is loaded");
}

OnDataLoaded {
    logger::info("Data loaded! Now I have access to all of the forms in the game");
}

OnNewGame {
    logger::info("Oh, hey! A new game was created!");
}
```

The following callback macros are available:

| | Timing | SKSE Event |
|-|-|-|
| `OnInit` | Runs immediately, as soon as the SKSE plugin is loaded. | n/a |
| `OnLoad`<br />`OnPluginLoad` | Runs as soon as all SKSE plugins have been loaded.<br />It can be preferable to run code here, as any code run in `OnInit` may run before other SKSE plugins have loaded. | `kPostLoad` |
| `OnPluginsLoaded` | Runs immediately after `OnLoad`. Infrequently used, but can be useful for coordinating messaging with other plugins. | `kPostPostLoad` |
| `OnLoadingGame` | Runs _before_ the savegame is loaded by Skyrim.<br />`TODO: provide a way to get the size/path of the .ess save game` | `kPreLoadGame` |
| `OnLoadedGame` | Runs _after_ the savegame has been loaded by Skyrim.<br />`TODO: provide a way to get whether load was successful` | `kPostLoadGame` |
| `OnSaveGame` | Runs when saving a game | `kSaveGame` |
| `OnDeleteGame` | Runs when deleting a game | `kDeleteGame` |
| `OnNewGame` | Runs after a new game has been created, but before the game has loaded | `kNewGame` |
| `OnInputLoaded` | Runs after the game's input initializes, right before the Main Menu initializes | `kInputLoaded` |
| `OnDataLoaded`<br />`OnFormsLoaded` | Runs after all of the game mods have been loaded (all Forms are loaded) | `kDataLoaded` |

### Providing your own `SKSEPluginLoad`

If you really want to provide your own `SKSEPluginLoad`, just make sure to call `SkyrimScripting::Plugin::Initialize()`.

```cpp
SKSEPluginLoad(const SKSE::LoadInterface *skse) {
    SKSE::Init(skse);
    // Your code
    // Note: this is where OnInit { ... } code runs
    SkyrimScripting::Plugin::Initialize();
    // Your code
    return true;
}
```

This will:
- Initialize the log
- Run the `OnInit` handlers

## Game Events (`On<EventType>`)

Game events are events like `RE::TESActivateEvent` and `RE::TESHitEvent` and more.

If you want to find out whenever one of these events happens in the game:

```cpp
#include <SkyrimScripting/Plugin.h>

EventHandlers {
    On<RE::TESActivateEvent>([](const RE::TESActivateEvent* event) {
        auto activator = event->actionRef ? event->actionRef->GetBaseObject()->GetName() : "";
        auto activated = event->objectActivated ? event->objectActivated->GetBaseObject()->GetName() : "";
        logger::info("{} activated {}", activator, activated);
    });

    // Basically:
    On<TheEventType>([](const TheEventType* event) {
        // Then, in here, you can do things with the event.
        // The `event` will store fields about the event.
    });
}
```

> To find events, I recommend searching [CommonLibSSE](https://github.com/CharmedBaryon/CommonLibSSE-NG) for files with `TES*Event` in their names.
> 
> 1. Visit this link: https://github.com/CharmedBaryon/CommonLibSSE-NG
> 2. Press the `T` key to open the fuzzy find file search
> 3. Type `TESEvent`
> 4. Choose any of the files that show up! They're probably events that you can get via an event sink 😸
>
> _Note: not all events have defined structures. You want to find ones which have their own files defined._

That's all... for now!
