# MAVLink-M C library (v2)

Generated MAVLink 2 C headers for the
[MAVLink-M](https://github.com/Dronecode/mavlink-military) dialect.

This repository is written by CI. Every commit here is generated from a commit
in [Dronecode/mavlink-military](https://github.com/Dronecode/mavlink-military),
and the commit subject matches the source commit it was built from. Don't edit
these files by hand or open pull requests here: changes will be overwritten on
the next generation. Propose message changes against `military.xml` in the
source repository instead.

## Using it

The headers are header-only C and need no build step. Add the repository as a
submodule (or vendor a copy), put its root on your include path, and include
the dialect:

```sh
git submodule add https://github.com/Dronecode/mavlink-military-c_library_v2.git \
  mavlink/c_library_v2
```

```c
#include "military/mavlink.h"
```

`military/mavlink.h` pulls in `common`, `standard` and `minimal`, so the full
common message set is available alongside the MAVLink-M messages. The dialect
definition the headers were generated from is kept in `message_definitions/`
for reference.

## Traceability

Each commit message records:

- the source commit in `Dronecode/mavlink-military` (short SHA and link)
- the pinned `mavlink` and `pymavlink` revisions used to generate it

To generate the headers yourself, or for another language, see the
[source repository](https://github.com/Dronecode/mavlink-military#using-it).

## License

MIT. See [`LICENSE`](LICENSE).
