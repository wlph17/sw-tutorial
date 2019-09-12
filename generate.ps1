$files = "kickoff", "tutorial1", "tutorial2"
foreach ($f in $files) {
    cleaver "$($f).md"
    ((Get-Content -path "$($f).html" -Raw) -replace 'var nextPosition','var p = position + n; if (p <= 0 || p > numSlides) return; var nextPosition') | Set-Content -Path "$($f).html"
}
