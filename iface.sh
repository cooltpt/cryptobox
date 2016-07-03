#!/bin/bash

echo "const gchar* iface = "
cat iface.glade | sed -e 's/\"/\\\"/g' -e 's/^/\"/' -e 's/$/\\n\"/'
echo ";"
