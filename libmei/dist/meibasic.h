
class MEIBasic {
public:
    static bool IsAllowed(const std::string &element, const std::string &attr)
    {
        if (attr == "xml:id") return true;
        if (!MEIBasic::map.count(element)) return false;
        const std::vector<std::string> &attributes = MEIBasic::map.at(element);
        return (std::find(attributes.begin(), attributes.end(), attr) != attributes.end());
    }

    // clang-format off
    
    inline static std::map<std::string, std::vector<std::string>> map = {
        {"arpeg", {"label", "type", "order", "layer", "plist", "staff", "tstamp", "startid", "arrow", "arrow.shape", "arrow.size", "arrow.color", "arrow.fillcolor", "line.form", "line.width", "fontfam", "fontname", "fontsize", "fontstyle", "fontweight", "letterspacing", "lineheight"}},
        {"beam", {"label", "type", "layer", "staff", "cue"}},
        {"beatRpt", {"label", "type", "beatdef", "layer", "staff", "slash", "expand", "fontfam", "fontname", "fontsize", "fontstyle", "fontweight", "letterspacing", "lineheight", "plist"}},
        {"breath", {"label", "type", "layer", "staff", "startid", "tstamp", "place", "fontfam", "fontname", "fontsize", "fontstyle", "fontweight", "letterspacing", "lineheight"}},
        {"bTrem", {"label", "type", "form", "layer", "staff", "dots", "dur", "num", "num.place", "num.visible", "unitdur"}},
        {"fermata", {"label", "type", "layer", "plist", "staff", "tstamp", "endid", "startid"}},
        {"fTrem", {"label", "type", "form", "layer", "staff", "dots", "dur", "unitdur"}},
        {"gliss", {"label", "type", "layer", "plist", "staff", "tstamp", "dur", "endid", "startid", "tstamp2", "fontfam", "fontname", "fontsize", "fontstyle", "fontweight", "letterspacing", "lineheight", "lendsym", "lendsym.size", "lstartsym", "lstartsym.size", "lform", "lsegs", "lwidth"}},
        {"graceGrp", {"label", "type", "attach", "layer", "staff", "grace", "grace.time"}},
        {"hairpin", {"label", "type", "form", "niente", "layer", "plist", "staff", "tstamp", "dur", "endid", "startid", "tstamp2", "opening", "closed", "opening.vertical", "angle.optimize", "lform", "lsegs", "lwidth", "place", "val", "val2"}},
        {"halfmRpt", {"label", "type", "layer", "staff", "dur", "expand", "fontfam", "fontname", "fontsize", "fontstyle", "fontweight", "letterspacing", "lineheight"}},
        {"harpPedal", {"label", "type", "c", "d", "e", "f", "g", "a", "b", "layer", "plist", "staff", "tstamp", "endid", "startid", "place", "fontfam", "fontname", "fontsize", "fontstyle", "fontweight", "letterspacing", "lineheight"}},
        {"lv", {"label", "type", "layer", "plist", "staff", "tstamp", "endid", "startid", "tstamp2", "curvedir"}},
        {"measure", {"label", "type", "left", "right", "metcon", "n"}},
        {"mNum", {"label", "type", "xml:lang", "place", "fontfam", "fontname", "fontsize", "fontstyle", "fontweight", "letterspacing", "lineheight"}},
        {"mRest", {"label", "type", "cue", "dur", "layer", "staff", "cutout", "fontfam", "fontname", "fontsize", "fontstyle", "fontweight", "letterspacing", "lineheight"}},
        {"mRpt", {"label", "type", "layer", "staff", "num", "expand", "num.place", "num.visible", "fontfam", "fontname", "fontsize", "fontstyle", "fontweight", "letterspacing", "lineheight"}},
        {"multiRest", {"label", "type", "layer", "staff", "num", "block", "num.place", "num.visible", "fontfam", "fontname", "fontsize", "fontstyle", "fontweight", "letterspacing", "lineheight", "width"}},
        {"multiRpt", {"label", "type", "layer", "staff", "num", "expand", "fontfam", "fontname", "fontsize", "fontstyle", "fontweight", "letterspacing", "lineheight"}},
        {"octave", {"label", "type", "coll", "layer", "plist", "staff", "tstamp", "dur", "dis", "dis.place", "endid", "startid", "tstamp2"}},
        {"pedal", {"label", "type", "dir", "func", "layer", "plist", "staff", "tstamp", "endid", "startid", "tstamp2", "form", "lendsym", "lendsym.size", "lstartsym", "lstartsym.size", "lform", "lsegs", "lwidth", "place", "fontfam", "fontname", "fontsize", "fontstyle", "fontweight", "letterspacing", "lineheight"}},
        {"reh", {"label", "type", "xml:lang", "staff", "startid", "tstamp", "place", "fontfam", "fontname", "fontsize", "fontstyle", "fontweight", "letterspacing", "lineheight"}},
        {"repeatMark", {"label", "type", "xml:lang", "func", "layer", "plist", "staff", "tstamp", "dur", "endid", "startid", "tstamp2", "place"}},
        {"slur", {"label", "type", "layer", "plist", "staff", "tstamp", "dur", "endid", "startid", "tstamp2", "curvedir"}},
        {"tie", {"label", "type", "layer", "plist", "staff", "tstamp", "endid", "startid", "tstamp2", "curvedir"}},
        {"tuplet", {"label", "type", "dur", "num", "numbase", "layer", "staff", "endid", "startid", "bracket.place", "bracket.visible", "dur.visible", "num.format", "num.place", "num.visible"}},
        {"mordent", {"label", "type", "form", "long", "layer", "plist", "staff", "tstamp", "endid", "startid", "accidupper", "accidlower", "accidupper.ges", "accidlower.ges", "place", "fontfam", "fontname", "fontsize", "fontstyle", "fontweight", "letterspacing", "lineheight"}},
        {"trill", {"label", "type", "layer", "plist", "staff", "tstamp", "dur", "accidupper", "accidlower", "accidupper.ges", "accidlower.ges", "endid", "startid", "tstamp2", "place", "fontfam", "fontname", "fontsize", "fontstyle", "fontweight", "letterspacing", "lineheight"}},
        {"turn", {"label", "type", "delayed", "form", "layer", "plist", "staff", "tstamp", "accidupper", "accidlower", "accidupper.ges", "accidlower.ges", "startid", "place", "fontfam", "fontname", "fontsize", "fontstyle", "fontweight", "letterspacing", "lineheight"}},
        {"fing", {"label", "type", "layer", "plist", "staff", "tstamp", "dur", "endid", "startid", "tstamp2", "place"}},
        {"fingGrp", {"label", "type", "form", "layer", "plist", "staff", "tstamp", "dur", "endid", "startid", "tstamp2"}},
        {"chordDef", {"label", "type", "tab.pos", "tab.strings"}},
        {"chordMember", {"label", "type", "accid.ges", "pname", "oct", "tab.fing", "tab.fret", "tab.string"}},
        {"chordTable", {"label", "type"}},
        {"f", {"label", "type", "layer", "plist", "staff", "tstamp", "dur", "endid", "startid", "tstamp2", "place"}},
        {"fb", {"label", "type"}},
        {"harm", {"label", "type", "chordref", "layer", "plist", "staff", "tstamp", "dur", "endid", "startid", "tstamp2"}},
        {"availability", {"label", "type", "data"}},
        {"fileDesc", {"label", "type", "corresp"}},
        {"meiHead", {"label", "xml:lang", "type"}},
        {"pubStmt", {"label", "type"}},
        {"titleStmt", {"label", "type"}},
        {"refrain", {"label", "type", "xml:lang", "place", "fontfam", "fontname", "fontsize", "fontstyle", "fontweight", "letterspacing", "lineheight", "voltasym"}},
        {"verse", {"label", "type", "xml:lang", "place", "fontfam", "fontname", "fontsize", "fontstyle", "fontweight", "letterspacing", "lineheight", "voltasym"}},
        {"volta", {"label", "type", "xml:lang", "fontfam", "fontname", "fontsize", "fontstyle", "fontweight", "letterspacing", "lineheight"}},
        {"instrDef", {"label", "n", "type", "midi.channel", "midi.duty", "midi.port", "midi.track", "midi.instrnum", "midi.instrname", "midi.pan", "midi.patchname", "midi.patchnum", "midi.volume", "azimuth", "elevation"}},
        {"persName", {"label", "type", "xml:lang", "nymref", "role", "enddate", "isodate", "notafter", "notbefore", "startdate"}},
        {"accid", {"label", "type", "func", "accid", "layer", "plist", "staff", "tstamp", "accid.ges"}},
        {"artic", {"label", "type", "artic", "layer", "plist", "staff", "tstamp", "onstaff", "place", "fontfam", "fontname", "fontsize", "fontstyle", "fontweight", "letterspacing", "lineheight"}},
        {"body", {"label", "type"}},
        {"caesura", {"label", "type", "layer", "staff", "startid", "tstamp", "place", "fontfam", "fontname", "fontsize", "fontstyle", "fontweight", "letterspacing", "lineheight"}},
        {"chord", {"label", "type", "dots", "grace", "grace.time", "cue", "dur", "layer", "staff", "instr", "stem.dir", "stem.len", "stem.mod"}},
        {"clef", {"label", "type", "layer", "staff", "cautionary", "shape", "line", "oct", "dis", "dis.place", "fontfam", "fontname", "fontsize", "fontstyle", "fontweight", "letterspacing", "lineheight"}},
        {"clefGrp", {"label", "type", "layer", "staff"}},
        {"date", {"label", "type", "calendar", "enddate", "isodate", "notafter", "notbefore", "startdate", "xml:lang"}},
        {"dir", {"label", "type", "xml:lang", "layer", "plist", "staff", "tstamp", "dur", "endid", "startid", "tstamp2", "place"}},
        {"dynam", {"label", "type", "layer", "plist", "staff", "tstamp", "dur", "endid", "startid", "tstamp2", "place", "xml:lang"}},
        {"label", {"label", "type", "xml:lang"}},
        {"labelAbbr", {"label", "type", "xml:lang"}},
        {"layer", {"label", "n", "type"}},
        {"lb", {"label", "type"}},
        {"mdiv", {"label", "type", "attacca", "n"}},
        {"mei", {"meiversion"}},
        {"music", {"label", "type"}},
        {"note", {"label", "type", "dots", "cue", "dur", "layer", "staff", "grace", "grace.time", "pname", "oct", "stem.dir", "stem.len", "stem.mod", "fontfam", "fontname", "fontsize", "fontstyle", "fontweight", "letterspacing", "lineheight", "oct.ges", "pname.ges", "instr", "vel", "tab.fing", "tab.fret", "tab.string"}},
        {"ornam", {"label", "type", "layer", "plist", "staff", "tstamp", "dur", "accidupper", "accidlower", "accidupper.ges", "accidlower.ges", "endid", "startid", "tstamp2", "place"}},
        {"pb", {"label", "type", "folium"}},
        {"pgFoot", {"label", "type", "xml:lang", "halign", "func"}},
        {"pgHead", {"label", "type", "xml:lang", "halign", "func"}},
        {"pubPlace", {"label", "type", "xml:lang"}},
        {"rend", {"label", "type", "halign", "xml:lang", "altrend", "rend", "fontfam", "fontname", "fontsize", "fontstyle", "fontweight", "letterspacing", "lineheight", "valign", "xml:space", "rotation"}},
        {"respStmt", {"label", "type"}},
        {"rest", {"label", "type", "dots", "cue", "dur", "layer", "staff", "fontfam", "fontname", "fontsize", "fontstyle", "fontweight", "letterspacing", "lineheight", "instr"}},
        {"sb", {"label", "type", "form", "fontfam", "fontname", "fontsize", "fontstyle", "fontweight", "letterspacing", "lineheight"}},
        {"score", {"label", "type"}},
        {"scoreDef", {"label", "type", "key.sig", "meter.count", "meter.unit", "meter.sym"}},
        {"section", {"label", "type", "attacca", "restart"}},
        {"space", {"label", "type", "dots", "dur", "layer", "staff", "compressable", "cutout"}},
        {"staff", {"label", "n", "type"}},
        {"staffDef", {"label", "n", "type", "lines", "clef.shape", "clef.line", "clef.dis", "clef.dis.place", "key.sig", "meter.count", "meter.unit", "meter.sym", "trans.diat", "trans.semi", "instr", "tab.strings", "ppq", "tune.Hz", "tune.pname", "tune.temper"}},
        {"staffGrp", {"label", "type", "bar.thru", "symbol", "instr"}},
        {"syl", {"label", "type", "xml:lang", "con", "wordpos", "place", "fontfam", "fontname", "fontsize", "fontstyle", "fontweight", "letterspacing", "lineheight", "halign"}},
        {"tempo", {"label", "type", "xml:lang", "func", "layer", "plist", "staff", "tstamp", "mm", "mm.unit", "mm.dots", "endid", "startid", "tstamp2", "place", "midi.bpm", "midi.mspb"}},
        {"title", {"label", "xml:lang", "n", "level", "type"}},
        {"barre", {"label", "type", "endid", "startid", "fret"}},
    };

    // clang-format on
};