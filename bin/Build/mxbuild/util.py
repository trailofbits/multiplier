#
# Copyright (c) 2022-present, Trail of Bits, Inc.
# All rights reserved.
#
# This source code is licensed in accordance with the terms specified in
# the LICENSE file found in the root directory of this source tree.
#


class AttrDict(dict):
    """Dictionary class with attribute-style access. It maps attribute access to
    the real dictionary."""

    def __init__(self, *args, **kwargs):
        super(AttrDict, self).__init__(*args, **kwargs)

    def __getstate__(self):
        return self.__dict__.items()

    def __setstate__(self, items):
        for key, val in items:
            self.__dict__[key] = val

    def __repr__(self):
        return "%s(%s)" % (self.__class__.__name__, dict.__repr__(self))

    def __setitem__(self, key, value):
        return super(AttrDict, self).__setitem__(key, value)

    def __getitem__(self, name):
        def convert_to(data):
            if isinstance(data, dict):
                return AttrDict(data)
            elif isinstance(data, list):
                for i in range(len(data)):
                    data[i] = convert_to(data[i])
                return data
            else:
                return data

        try:
            return convert_to(super(AttrDict, self).__getitem__(name))
        except KeyError:
            raise AttributeError("'{}'".format(name))

    def __delitem__(self, name):
        return super(AttrDict, self).__delitem__(name)

    def copy(self):
        return AttrDict(self)

    __getattr__ = __getitem__
    __setattr__ = __setitem__
