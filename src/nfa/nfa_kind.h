/*
 * Copyright (c) 2015-2016, Intel Corporation
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 *  * Redistributions of source code must retain the above copyright notice,
 *    this list of conditions and the following disclaimer.
 *  * Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 *  * Neither the name of Intel Corporation nor the names of its contributors
 *    may be used to endorse or promote products derived from this software
 *    without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE
 * LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
 * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 */

/**
 * \file
 * \brief Data structures and helper functions used to describe the purpose of
 * a particular NFA engine at build time.
 */

#ifndef NFA_KIND_H
#define NFA_KIND_H

#include "ue2common.h"

namespace ue2 {

/** \brief Specify the use-case for an nfa engine. */
enum nfa_kind {
    NFA_PREFIX, //!< rose prefix
    NFA_INFIX,  //!< rose infix
    NFA_SUFFIX, //!< rose suffix
    NFA_OUTFIX,  //!< "outfix" nfa not triggered by external events
    NFA_OUTFIX_RAW, //!< "outfix", but with unmanaged reports
    NFA_REV_PREFIX, //! reverse running prefixes (for som)
};

/** \brief True if this kind of engine is triggered by a top event. */
inline
bool is_triggered(enum nfa_kind k) {
    switch (k) {
    case NFA_INFIX:
    case NFA_SUFFIX:
    case NFA_REV_PREFIX:
        return true;
    default:
        return false;
    }
}

/**
 * \brief True if this kind of engine generates callback events when it
 * enters accept states.
 */
inline
bool generates_callbacks(enum nfa_kind k) {
    switch (k) {
    case NFA_SUFFIX:
    case NFA_OUTFIX:
    case NFA_OUTFIX_RAW:
    case NFA_REV_PREFIX:
        return true;
    default:
        return false;
    }
}

/**
 * \brief True if this kind of engine has reports that are managed by the \ref
 * ReportManager.
 */
inline
bool has_managed_reports(enum nfa_kind k) {
    switch (k) {
    case NFA_SUFFIX:
    case NFA_OUTFIX:
        return true;
    default:
        return false;
    }
}

} // namespace ue2

#endif
